#!/bin/bash

# ========================================
# C++ Module 01, Exercise 04 Test Script
# Tests error handling and edge cases.
# ========================================

# --- Configuration ---
EXEC_NAME="./Cfile"
TEST_FILE="test_input.txt"
REPLACE_FILE="${TEST_FILE}.replace"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Ensure the executable exists
if [ ! -f "$EXEC_NAME" ]; then
    echo -e "${RED}ERROR: Executable '$EXEC_NAME' not found. Compile first!${NC}"
    exit 1
fi

# Clean up function
cleanup() {
    rm -f $TEST_FILE $REPLACE_FILE secured.txt readable.txt filename1.txt filename1.txt.replace
    rmdir 2>/dev/null readable.txt.replace
}

# --- Test Functions ---

test_error() {
    TEST_NAME="$1"
    shift
    echo -n "  [TEST] $TEST_NAME... "
    # Run the command, suppress normal output, check if it fails (exit code > 0)
    "$EXEC_NAME" "$@" > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${GREEN}PASS${NC} (Error detected)"
    else
        echo -e "${RED}FAIL${NC} (Did not exit on error)"
    fi
}

test_logic() {
    TEST_NAME="$1"
    CONTENT="$2"
    S1="$3"
    S2="$4"
    EXPECTED="$5"

    echo "$CONTENT" > "$TEST_FILE"
    
    echo -n "  [TEST] $TEST_NAME... "
    "$EXEC_NAME" "$TEST_FILE" "$S1" "$S2" > /dev/null 2>&1

    if [ $? -eq 0 ] && [ -f "$REPLACE_FILE" ] && [ "$(cat "$REPLACE_FILE")" = "$EXPECTED" ]; then
        echo -e "${GREEN}PASS${NC} (Output matched)"
    else
        echo -e "${RED}FAIL${NC} (Expected: '$EXPECTED' | Got: '$(cat "$REPLACE_FILE" 2>/dev/null)')${NC}"
    fi
}

# --- New function for the big file test ---
test_mega_file() {
    TEST_NAME="Mega File Stress Test"
    # Content of filename1.txt is used here
    CONTENT="Understanding memory management is a critical skill in C++. Manual memory control gives the programmer great power, but also great responsibility. A common issue is the memory leak, which occurs when dynamic memory is allocated but never freed. This kind of memory mismanagement can cause a program to slow down and eventually crash.\n\nTo avoid memory problems, one must be diligent. Every 'new' must have a matching 'delete'. This applies to single allocations of memory and array allocations of memory. The rules of storage are strict. Forgetting to free storage is a serious bug.\n\nGood memory hygiene leads to stable and efficient applications. Tracking every piece of dynamic memory is not always easy, but tools like Valgrind can help detect memory errors. Proper C++ memory handling is a sign of a skilled developer."
    S1="memory"
    S2="storage"
    EXPECTED="Understanding storage management is a critical skill in C++. Manual storage control gives the programmer great power, but also great responsibility. A common issue is the storage leak, which occurs when dynamic storage is allocated but never freed. This kind of storage mismanagement can cause a program to slow down and eventually crash.\n\nTo avoid storage problems, one must be diligent. Every 'new' must have a matching 'delete'. This applies to single allocations of storage and array allocations of storage. The rules of storage are strict. Forgetting to free storage is a serious bug.\n\nGood storage hygiene leads to stable and efficient applications. Tracking every piece of dynamic storage is not always easy, but tools like Valgrind can help detect storage errors. Proper C++ storage handling is a sign of a skilled developer."

    # Create the test file with the content
    echo -e "$CONTENT" > "filename1.txt"
    
    echo -n "  [STRESS] $TEST_NAME... "
    "$EXEC_NAME" "filename1.txt" "$S1" "$S2" > /dev/null 2>&1

    if [ $? -eq 0 ] && [ -f "filename1.txt.replace" ] && [ "$(cat "filename1.txt.replace")" = "$(echo -e "$EXPECTED")" ]; then
        echo -e "${GREEN}PASS${NC} (Mega file replacement OK)"
    else
        echo -e "${RED}FAIL${NC} (Replacement or integrity check failed)${NC}"
    fi
}
# =================================================================
# --- RUN TESTS ---
# =================================================================

cleanup
echo -e "${YELLOW}--- 1. ARGUMENT ERROR TESTS ---${NC}"
test_error "No arguments"
test_error "Too few arguments" "file.txt" "A"
test_error "Too many arguments" "file.txt" "A" "B" "C"
test_error "s1 is empty (CRITICAL)" "file.txt" "" "B" # Should catch empty s1 for safety

cleanup
echo -e "\n${YELLOW}--- 2. FILE ERROR TESTS (I/O) ---${NC}"
test_error "Input file does not exist" "file_not_found.txt" "A" "B"

# Test: No read permission (Create a file, remove read permission)
echo "secret" > "secured.txt"
chmod 000 "secured.txt" 
test_error "No read permissions" "secured.txt" "A" "B"
chmod 644 "secured.txt" # Restore permissions for cleanup

# Test: Output file is a directory (Cannot write)
echo "data" > "readable.txt"
mkdir "readable.txt.replace" 2>/dev/null
test_error "Output is a directory" "readable.txt" "A" "B"

cleanup
echo -e "\n${YELLOW}--- 3. LOGIC & EDGE CASE TESTS ---${NC}"

# 3a. Simple Cases
test_logic "Simple replacement" "Hello World" "World" "42" "Hello 42"
test_logic "No match found" "Testing 123" "ABC" "XYZ" "Testing 123"

# 3b. Multiple Occurrences
test_logic "Multiple hits" "one two one two" "one" "three" "three two three two"

# 3c. Overlapping/Adjacent Replacements
test_logic "Adjacent replacement" "Hello$$World" "$$" "XX" "HelloXXWorld"

# 3d. Replacement at Start/End
test_logic "Start/End replacement" "START MIDDLE END" "START" "BEGIN" "BEGIN MIDDLE END"
test_logic "Start/End replacement" "START MIDDLE END" "END" "FINISH" "START MIDDLE FINISH"

# 3e. Replacement of multi-line content
test_logic "Multi-line replacement" "First Line.\nSecond Line." "Line" "Code" "First Code.\nSecond Code."

echo -e "\n${YELLOW}--- 4. STRESS TEST (MEMORY -> STORAGE) ---${NC}"
test_mega_file

# --- Final Cleanup ---
cleanup
echo -e "\n${YELLOW}--- TESTING COMPLETE ---${NC}"