ejecutar : clase25.x
	./clase25.x 

clase25.x : clase25.cpp
	c++ clase25.cpp -o clase25.x
	
clean : 
	rm clase25.x clase25.dat
