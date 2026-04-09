: '
Kyle Longrich 

Note on Device ID Consistency: When running ls -l /dev on pseudo-devices like dtrace or autofs_ nodes, the minor numbers (and thus the dev_t hex value) are dynamically assigned by the kernel at runtime. Because these assignments are non-persistent across system reboots or service restarts, binary comparisons of ls output for these files will likely show discrepancies in the minor device field.

'

clear
choice="1"
tests="tests"
result=.
touch mine other

check ()
{
	$left > mine 2> /dev/null |:
	$right > other 2> /dev/null |:
	
	out="$(diff mine other)"
	
	if [ "$out" != "" ]
	then
		result=!
		color="$(tput setaf 1)"
		echo $left >> errors
		((error++))
	else
		result=.
		echo $left >> passed
		((passed++))
	fi
	((count++))
}

while true; do

read  -d'' -s -n1

if [ "$REPLY" == "3" ]
	then
		rm -f mine other errors
		break
elif [ "$REPLY" == "2" ]
	then
		clear
		read x
		clear
		echo $x >> tests
else
	clear
	echo "Running......"
	make re
	make clean
	rm -f errors
	rm -f passed

	color="$(tput setaf 2)"
	final="Basic Test: ["
	count=0
	error=0
	while read -r line
	do
		right="$line"
		left="./ft_$line"
		check
		final="$final $result"
	done < "$tests"

	clear

	echo "$color$final ]"
	if [ "$error" -gt "0" ];
	then
		echo "$(tput setaf 1)\n FAILED TEST"
		cat errors
		echo "$(tput setaf 2)\n PASSED TEST"
		cat passed
	fi
	if [ "$error" -eq "0" ];
	then
		echo "$(tput setaf 2)\nALL TEST PASSED"
	else
		echo "$(tput setaf 1)"
		echo "\nFalied $error / $count "
	fi
	read -p "$(tput setaf 7)" opt
	clear
	fi
	clear
done
clear
