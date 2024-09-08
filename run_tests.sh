#!/bin/bash

# This script will allow you to run the tests associated with this exercise
# without having to wait for Vocareum to automatically grade it.
#
# The script will copy your code to the `TestResults` directory, attempt to
# build, and if successful, run the tests against your code.
#
# PLEASE NOTE!  The script clears the contents of the `TestResults` directory
# each time it is ran - DO NOT put anything in there that you don't want to lose!
#
# Usage:
#   chmod +x run_tests.sh
#   ./run_tests.sh


# Clear old test results.
rm -rf ./TestResults
mkdir TestResults

# Copy student code to TestResults directory.
cp -r system_info ./TestResults/system_info
cd TestResults

# Run tests.
total_tests=12
passed_tests=0
failed=0
history_file="system_info/command_history.txt"

echo "Test Suite: Check Command History Tests"
echo "***Found $total_tests Tests***"
echo 

echo "Running Test: Check for mkdir..."
if grep -q "mkdir ~/system_info" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: mkdir ~/system_info"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for cd..."
if grep -q "cd ~/system_info" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: cd ~/system_info"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for touch..."
if grep -q "touch info.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: touch info.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for pwd..."
if grep -q "pwd >> info.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: pwd >> info.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for ls..."
if grep -q "ls -l /etc >> info.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: ls -l /etc >> info.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for cp..."
if grep -q "cp /etc/os-release ~/system_info" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: cp /etc/os-release ~/system_info"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for mv..."
if grep -q "mv ~/system_info/os-release ~/system_info/os_details.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: mv ~/system_info/os-release ~/system_info/os_details.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for cat..."
if grep -q "cat os_details.txt >> info.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: cat os_details.txt >> info.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for uname..."
if grep -q "uname -a >> info.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: uname -a >> info.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for df..."
if grep -q "df -h >> info.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: df -h >> info.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for chmod..."
if grep -q "chmod 600 info.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: chmod 600 info.txt"
    failed=$((++failed))
    echo 
fi

echo "Running Test: Check for history..."
if grep -q "history | tail -n 12 > command_history.txt" $history_file; then
    echo "  [PASSED]"
    passed_tests=$((++passed_tests))
    echo 
else
    echo "  [FAILED] - Expected: history | tail -n 12 > command_history.txt"
    failed=$((++failed))
    echo 
fi

echo "Check Command History Tests results:"
if [ "$passed_tests" == "$total_tests" ]; then
    echo "  [PASSED] - Tests Ran: $total_tests, Tests Passed: $passed_tests, Tests Failed: $failed"
else
    echo "  [FAILED] - Tests Ran: $total_tests, Tests Passed: $passed_tests, Tests Failed: $failed"
fi
echo 
