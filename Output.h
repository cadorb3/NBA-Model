#ifndef OUTPUT_H_
#define OUTPUT_H_


// creation  of a template, also using the concept of functors


template<class T>
struct Output{
	void operator ()(T &x){


		x.Display();
	}
};






#endif /* OUTPUT_H_ */
