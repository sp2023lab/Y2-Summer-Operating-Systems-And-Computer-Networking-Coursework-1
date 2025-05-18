echo -n "Enter a filename"
read fileName
if [ -e "$filename" ]; then
	echo "File exists"
	if [ -f "$filename" ]; then
		echo "Regular file"
		echo -n "Enter word to search:"
		read searchWord
		grep -n "$searchWord" "$fileName"
		if [ $? -ne 0 ]; then
			echo "Word not found on file"
		fi
	elif [ -d "$filename" ]; then
		echo "Directory"
	else
		echo "Neither"
	fi
else
	echo "File does not exist"
fi
