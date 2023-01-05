#include <iostream>

void operation(char &op)
{
    std::cout << "Pleas enter operation:" << std::endl;
    std::cout << "encrypt  = 0" << std::endl;
    std::cout << "decipher = 1" << std::endl;

    while(true)
    {
        std::cin >> op;

        if(op == '0' || op == '1')
        {
            break;
        }
        else
        {
            std::cout << "Oops, that input is invalid.  Please try again." << std::endl;
        }
    }
}

void stringLenght(uint &lenght)
{
    std::cout << "Please enter the string length (max.4 294 967 295 symbol)" << std::endl;

    while(true)
    {
        std::cin >> lenght;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Oops, that input is invalid.  Please try again." << std::endl;
        }
        else
        {
            std::cin.ignore(32767,'\n');
            break;
        }
    }
}

void encryptStep(ushort &step)
{
    std::cout << "Pleas enter encoding step (from 1 to 25)" << std::endl;

    while(true)
    {
        std::cin >> step;

        if(step < 1 || step > 25)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Oops, that input is invalid.  Please try again." << std::endl;
        }
        else
        {
            std::cin.ignore(32767,'\n');
            break;
        }
    }
}

void coding(char &op, const uint &lenght, ushort &step, char *text)
{
    if(op == '1')
    {
        step = 26 - step;
    }
    
    for(int i = 0; i < lenght; ++i)
    {
        if(text[i] > 64 && text[i] < 91)
        {
            if(text[i] + step > 90)
            {
                text[i] -= 26 * (step / 26 + 1);
            }

            text[i] += step;
        }

        if(text[i] > 96 && text[i] < 123)
        {
            if(text[i] + step > 122)
            {
                text[i] -= 26 * (step / 26 + 1);
            }

            text[i] += step;
        }
    }

    std::cout << text << std::endl;

}

int main()
{
    while(true)
    {
        char op;
        operation(op);

        uint lenght;
        stringLenght(lenght);

        char *text = new char[lenght];  // HellomynameisDietrichandIhavesomenewsforyou

        ushort step;
        encryptStep(step);
        
        std::cout << "Pleas enter a string (no spaces or punctuation marks):" << std::endl;
        for(std::size_t i = 0; i < lenght; ++i)
        {
            text[i] = std::cin.get();
            if((!(text[i] >= 'A' && text[i] <= 'Z')) && (!(text[i] >= 'a' && text[i] <= 'z')))
            {
                if(text[i] == '\n')
                {
                    text[i] = 0;
                    break;
                }
                std::cin.ignore(32767,'\n');
                i = 0;
                std::cout << "Invalid input, please try again:" << std::endl;
                continue;
            }

        }
    
        coding(op, lenght, step, text);

        std::cout << "Recover string? y(yes) or n(no)" << std::endl;
        while(true)
        {
            char recover;
            std::cin >> recover;

            if(recover == 'y')
            {
                op = '1';
                coding(op, lenght, step, text);
                break;
            }
            else if(recover == 'n')
            {
                break;
            }
            else
            {
                std::cout << "Oops, that input is invalid.  Please try again." << std::endl;
                std::cin.ignore(32767,'\n');
            }
        }

        char newstring;
        do
        {
            std::cin.ignore(32767,'\n');
            std::cout << "New string? y(yes) or e to exit " << std::endl;
            std::cin >> newstring;
        }
        while(newstring != 'y' && newstring != 'e');
        
        if(newstring == 'e')
        {
            delete [] text;
            break;
        }
        else
        {
            delete [] text;
        }
    }
}