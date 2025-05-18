#!/bin/bash

# Define student ID and date suffix
STUDENT_ID="32010160"
DATE_SUFFIX=$(date +%s)

# Step 1: Create three directories
echo "Step 1: Create three directories"
mkdir ${STUDENT_ID}_project_${DATE_SUFFIX}
mkdir ${STUDENT_ID}_notes_${DATE_SUFFIX}
mkdir ${STUDENT_ID}_docs_${DATE_SUFFIX}

# Step 2: Create two files in each directory
echo "Step 2: Create two files in each directory"
for DIR in ${STUDENT_ID}_project_${DATE_SUFFIX} ${STUDENT_ID}_notes_${DATE_SUFFIX} ${STUDENT_ID}_docs_${DATE_SUFFIX}
do
    touch $DIR/${STUDENT_ID}_desc.txt
    touch $DIR/${STUDENT_ID}_ref.txt
done

# Step 3: Add sample content to each file
echo "Step 3: Add sample content to each file"
echo "This directory stores Bash scripting project files." > ${STUDENT_ID}_project_${DATE_SUFFIX}/${STUDENT_ID}_desc.txt
echo "These scripts are part of CS2ON coursework." > ${STUDENT_ID}_project_${DATE_SUFFIX}/${STUDENT_ID}_ref.txt

echo "This directory includes Linux command notes." > ${STUDENT_ID}_notes_${DATE_SUFFIX}/${STUDENT_ID}_desc.txt
echo "Topics include mkdir, touch, grep, strace, and permissions." > ${STUDENT_ID}_notes_${DATE_SUFFIX}/${STUDENT_ID}_ref.txt

echo "This directory contains supporting documents." > ${STUDENT_ID}_docs_${DATE_SUFFIX}/${STUDENT_ID}_desc.txt
echo "Documentation is related to coursework setup and processes." > ${STUDENT_ID}_docs_${DATE_SUFFIX}/${STUDENT_ID}_ref.txt

# Step 4: Search for keyword "coursework" in all files
echo "Step 4: Search for keyword 'coursework' in all files"
grep -r "coursework" ${STUDENT_ID}_*

# Step 5: List contents of one directory with detailed info
echo "Step 5: List contents of one directory with detailed info"
ls -l ${STUDENT_ID}_notes_${DATE_SUFFIX}

# Step 6: Copy content of one file and rename it
echo "Step 6: Copy content of one file and rename it"
cp ${STUDENT_ID}_docs_${DATE_SUFFIX}/${STUDENT_ID}_desc.txt ${STUDENT_ID}_docs_${DATE_SUFFIX}/${STUDENT_ID}_copy.txt
mv ${STUDENT_ID}_docs_${DATE_SUFFIX}/${STUDENT_ID}_copy.txt ${STUDENT_ID}_docs_${DATE_SUFFIX}/${STUDENT_ID}_renamed.txt

# Step 7: Run strace on the script in a subshell
echo "Step 7: Run strace on the script (External Command)"
