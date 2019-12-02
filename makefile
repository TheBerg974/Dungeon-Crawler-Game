projectmake: answers.c addgold.c
	gcc -o ./cgi-bin/answers.cgi answers.c
	gcc -o ./cgi-bin/addgold.cgi addgold.c

