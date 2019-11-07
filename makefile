ejecutar : clase26.x
	./clase26.x 

clase26.x : clase26.cpp
	c++ clase26.cpp -o clase26.x
	
clean : 
	rm clase26.x multiplicados.dat arreglo.dat
