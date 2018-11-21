#include "Square.h"

Square::Square(std::string name, float width)
	:Rectangle(name,width,width)	
{

}

void Square::Draw()
{
	std::cout<<"this is "<<this->getName()<<"\n";
        std::cout<<"\n";
        std::cout<<"width of "<<this->getName()<<" is "<<width<<"\n";
        std::cout<<"height of "<<this->getName()<<" is "<<width<<"\n";

        int i,j;
        std::cout<<"\n";
        std::cout<<"the image is \n";
        std::cout<<"\n";
        for(i=0;i<width;i++)
                {
                if(i == 0 || i == width - 1)
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

