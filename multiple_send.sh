i=0
while [ $i -ne 50 ]
do
	./client $1 "Message $i\n"
	i=$(($i+1))
done
