# IF script
# Input from the keyboard
echo "Do you want to exit (y/n)?"
read answer
if [ "$answer" = y ]; then
	echo "Exiting..."
	exit 0
else
	echo "NOT Exiting"
	exit 0
fi
