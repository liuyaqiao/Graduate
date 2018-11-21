#include "Rectangle.h"


// The constructor of class Rectangle first invokes the constructior of parent "shape" by forwarding argument 'name' into it. We do that by writing ": Shape[name]" between the function header and the "{" symbol.
Rectangle::Rectangle(std::string name,float width,float height)
	: Shape(name)
{
	this->width = width;
	this->height = height;
}

float Rectangle::getArea()
{
	return width*height;
}

void Rectangle::Draw()
{
	std::cout<<"this is "<<this->getName()<<"\n";
	std::cout<<"\n";
	std::cout<<"width of "<<this->getName()<<" is "<<width<<"\n";
	std::cout<<"height of "<<this->getName()<<" is "<<height<<"\n";

	int i,j;
	std::cout<<"\n";
	std::cout<<"the image is \n";
	std::cout<<"\n";
	for(i=0;i<height;i++)
		{
		if(i == 0 || i == height - 1)
			for(j=0;j<width;j++)
				std::cout<<"* ";	
		else
			{
			for(j=0;j<width;j++)
				if(j==0||j==width-1)
					std::cout<<"* ";
				else
					std::cout<<"  ";
			}	
	

		std::cout<<std::endl;
		}		
	



}
