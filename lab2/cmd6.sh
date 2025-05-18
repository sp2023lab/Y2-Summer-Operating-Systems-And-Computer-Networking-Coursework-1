echo "Enter the first number"
read firstInteger
echo "Enter the second number"
read secondInteger
if [ "$firstInteger" -ne "$secondInteger" ]; then
	if [ "$firstInteger" -gt "$secondInteger" ]; then
		echo "$firstInteger is greater than $secondInteger"
	else
		echo "$secondInteger is greater than $firstInteger"
	fi
else
	echo "They are equal"
fi
