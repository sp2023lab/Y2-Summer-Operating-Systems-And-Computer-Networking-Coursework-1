echo "Enter the temperature in celsius:"
read temperature
if [ $temperature -gt 24 ]; then
	echo "Warm weather"
else
	echo "Cold weather"
fi
