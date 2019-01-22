
/*

        ____  ____  ________ __________  ______
       / __ \/ __ \/ ____/ //_/_  __/ / / / __ \
      / / / / / / / /   / ,<   / / / / / / /_/ /
     / /_/ / /_/ / /___/ /| | / / / /_/ / _, _/
    /_____/\____/\____/_/ |_|/_/  \____/_/ |_|

	An app to meet all your health needs.
	A project by Arnesh K, Anvita N, Chandana S and Surabhi J
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <process.h>
#include <windows.h>



using namespace std;

 struct user
{
    char Name[20] ;
    int age ;
    float weight ;
    float height ;
    float BMI ;
    char sex ;
    char disorder ;
};

 user custom ;                    //custom - short for customer, or the user who interacts with the app. This is the variable that represents the user throughout the programme.
 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //Retrieves a handle to the specified standard device. Basically, it's a pointer that refers to the output window, giving us the freedom to modify its size and attributes.

/****Here's a list of functions used in this program:****/
void Initialise() ;
void load() ;
void header() ;
float BMI(float weight , float height) ;
int cal () ;
void tips (char sex, char disorder, int meal, int cal) ;


 int water; // Global variables
 int opt;


int main()
{
    COORD winmax;
    SMALL_RECT rect;
    SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED) ; //Increasing the intensity of all the basic colours (red, blue and green) will give the text a white colour.

    winmax.X = 100; winmax.Y = 50;
    rect.Top    = 0;
    rect.Left   = 0;
    rect.Bottom = winmax.Y - 1;
    rect.Right  = winmax.X - 1;
    SetConsoleScreenBufferSize(handle, winmax);      //Changes the size of the specified console screen buffer.
    SetConsoleWindowInfo(handle, TRUE, &rect);       //Sets the current size and position of a console screen buffer's window.

    char opt ;
    COORD point ;
    point.X = 0 ;
    point.Y = 20 ;
    SetConsoleCursorPosition(handle,point) ;

    cout << setw(79) << " ______  _______ _______ _      _________        _______ " << endl;
    cout << setw(79) << "(  __  \\(  ___  |  ____ \\ \\    /\\__   __/\\     /(  ____ )" << endl;
    cout << setw(79) << "| (  \\  ) (   ) | (    \\/  \\  / /  ) (  | )   ( | (    )|" << endl;
    cout << setw(79) << "| |   ) | |   | | |     |  (_/ /   | |  | |   | | (____)|" << endl;
    cout << setw(79) << "| |   | | |   | | |     |   _ (    | |  | |   | |     __)" << endl;
    cout << setw(79) << "| |   ) | |   | | |     |  ( \\ \\   | |  | |   | | (\\ (   " << endl;
    cout << setw(79) << "| (__/  ) (___) | (____/\\  /  \\ \\  | |  | (___) | ) \\ \\__" << endl;
    cout << setw(79) << "(______/(_______|_______/_/    \\/  )_(  (_______)/   \\__/" << endl << endl;

    cout << setw(68) << "Press Y to continue or N to exit: " ;
    cin >> opt ;
    cin.ignore(1000,'\n');

    while (opt == 'Y' || opt == 'y')
    {
        system("cls") ;
        int calorie(0) ;
        Initialise() ;
        header() ;


        custom.BMI = BMI(custom.weight, custom.height) ;
        cout << endl << endl ;

        calorie = cal() ;

        tips(custom.sex , custom.disorder , opt , calorie ) ;
        cout << endl << endl << "Press Y to continue or N to exit: " ;
        cin >> opt ;
        getchar();
    }



    return 0;
}


void Initialise()
{
    char opt, flag = 'T' ;


    cout << setw(79) << " ______  _______ _______ _      _________        _______ " << endl;
    cout << setw(79) << "(  __  \\(  ___  |  ____ \\ \\    /\\__   __/\\     /(  ____ )" << endl;
    cout << setw(79) << "| (  \\  ) (   ) | (    \\/  \\  / /  ) (  | )   ( | (    )|" << endl;
    cout << setw(79) << "| |   ) | |   | | |     |  (_/ /   | |  | |   | | (____)|" << endl;
    cout << setw(79) << "| |   | | |   | | |     |   _ (    | |  | |   | |     __)" << endl;
    cout << setw(79) << "| |   ) | |   | | |     |  ( \\ \\   | |  | |   | | (\\ (   " << endl;
    cout << setw(79) << "| (__/  ) (___) | (____/\\  /  \\ \\  | |  | (___) | ) \\ \\__" << endl;
    cout << setw(79) << "(______/(_______|_______/_/    \\/  )_(  (_______)/   \\__/" << endl << endl;
    cout << setw(67) << "The best app for your health needs" <<endl ;
    cout << endl << endl ;





    cout << "Enter your name: " ;
    gets(custom.Name) ;
    cout << "Enter your age: " ;
    cin >> custom.age ;
    cout << "Enter your weight[kg]: " ;
    cin >> custom.weight ;
    cout << "Enter your height[cm]: " ;
    cin >> custom.height ;
    cout << "Enter your sex [M/F]: " ;
    do
    {
        flag = 'T' ;
        cin >> custom.sex ;
        if(custom.sex != 'M' && custom.sex != 'F')
        { cout << "Please enter a valid option!" ;
          flag = 'F' ;
        }
    } while (flag != 'T') ;



    flag = 'T' ;
    do
    {

        cout << "Do you have any of the following disorders?" << endl ;
        cout << "a.Diabetes \nb.Hypertension \nc.High Cholestrol \nd.Hyperthyroid \ne.None" ;
        cout << "\nEnter your option: " ;
        cin >> opt ;

        flag = 'T' ;
        switch (opt)
        {
        case 'a' :
            custom.disorder = 'D' ;           //D - Diabetes
            break ;

        case 'b' :
            custom.disorder = 'H' ;           //H - Hypertension
            break ;

        case 'c' :
            custom.disorder = 'C' ;           //C - Cholestrol
            break ;

        case 'd' :
            custom.disorder = 'T' ;           //T - HyperThyroid
            break ;
        case 'e' :
            custom.disorder = 'N' ;           //N - None
            break ;

        default :
            cout << "Please enter a valid option!" ;
            flag = 'F' ;
            break ;

        }

    }while (flag == 'F') ;

    system("cls") ;
    load() ;
}

void header()
{
    COORD point ;
    cout << setw(79) << " ______  _______ _______ _      _________        _______ " << endl;
    cout << setw(79) << "(  __  \\(  ___  |  ____ \\ \\    /\\__   __/\\     /(  ____ )" << endl;
    cout << setw(79) << "| (  \\  ) (   ) | (    \\/  \\  / /  ) (  | )   ( | (    )|" << endl;
    cout << setw(79) << "| |   ) | |   | | |     |  (_/ /   | |  | |   | | (____)|" << endl;
    cout << setw(79) << "| |   | | |   | | |     |   _ (    | |  | |   | |     __)" << endl;
    cout << setw(79) << "| |   ) | |   | | |     |  ( \\ \\   | |  | |   | | (\\ (   " << endl;
    cout << setw(79) << "| (__/  ) (___) | (____/\\  /  \\ \\  | |  | (___) | ) \\ \\__" << endl;
    cout << setw(79) << "(______/(_______|_______/_/    \\/  )_(  (_______)/   \\__/" << endl << endl;
    cout << setw(67) << "The best app for your health needs" <<endl ;
    cout << endl << endl ;


    point.Y = 12 ;
    point.X = 5 ;
    SetConsoleCursorPosition(handle,point) ; point.Y++ ;
    cout << "Name: " << custom.Name ;
    SetConsoleCursorPosition(handle,point) ;
    cout << "Age: " << custom.age ;

    point.X += 70 ;
    point.Y = 12 ;
    SetConsoleCursorPosition(handle,point) ; point.Y++ ;
    cout << "Height: " << custom.height << " cm" ;
    SetConsoleCursorPosition(handle,point) ;
    cout << "Weight: " << custom.weight << " kg" ;
    cout << endl ;

}


float BMI(float weight , float height )
{
    float bmi(0) ;
    COORD point ;
    point.X = 40;
    point.Y = 14 ;
    bmi = (weight/ pow((height/100),2));
    cout<<"\n";
    SetConsoleCursorPosition(handle,point) ;
    cout <<"Your BMI is "<<bmi<<endl;

    if (bmi < 18.5)
       {
       SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY|FOREGROUND_RED); //Changing the colour of the text by increasing red intensity
       cout << setw(60) <<"You are underweight!"<<endl;
       SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ; //changing it back to white
       }
    else if (bmi >= 18.5 && bmi <25)
    {
       SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_GREEN) ; //Changing the colour of the text by increasing green intensity
       cout << setw(69) <<"Your BMI is in the appropriate range."<<endl;
       SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;//changing it back to white
    }

    else if (bmi >= 25 )
    {
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;//Changing the colour of the text by increasing red intensity
        cout << setw(60) <<"You are overweight!"<<endl;
        SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
    }
    else
       cout<<endl<<endl;


return bmi;

}

void tips (char sex, char disorder, int meal, int cal)
{   //for calorie intake

        if (meal == 1 || meal == 2 )              //Breakfast and Lunch
          {
              if (cal > 500)
              {
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;
                  cout << setw(82)<< "Your calorie intake for this meal is above the advisable level." << endl;
                  cout << setw(72)<< "Make efforts to reduce your calorie intake."<<endl;
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
              }

              else if (cal < 300)
              {
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;
                  cout << setw(82)<< "Your calorie intake for this meal is below the advisable level." << endl;
                  cout << setw(73)<< "Make efforts to increase your calorie intake."<<endl;
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
              }



          }


        else if (meal == 3 && cal>400)      //Dinner
        {
            if(cal > 400)
            {
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;
                  cout << setw(82)<< "Your calorie intake for this meal is above the advisable level." << endl;
                  cout << setw(72)<< "Make efforts to reduce your calorie intake."<<endl;
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
            }

            else if (cal < 200)
            {
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;
                  cout << setw(82)<< "Your calorie intake for this meal is below the advisable level." << endl;
                  cout << setw(73)<< "Make efforts to increase your calorie intake."<<endl;
                  SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
            }
        }




     //water intake
     cout << endl << endl;
     if (water<6)
     {
         cout<<"You're not drinking enough water! Make sure to drink at least 6-8 glasses a day."<<endl << endl ;
     }
     else
     {
         cout<<"You're drinking enough water... Keep it up!"<<endl<<endl;
     }

     //tips for disorder, else in general
     COORD tips_start ;
     tips_start.X = 0 ;
     tips_start.Y = 21 ;
     SetConsoleCursorPosition(handle,tips_start) ;
     cout<<"Here are some health rules to follow:"<<endl;

     switch (custom.disorder)
     {
         case 'D' :
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_GREEN) ;
            cout<<"Do:"<<endl;
            cout<<"___"<<endl ;
            cout<<"Adopt a high protein diet!"<<endl;
            cout<<"Eat lots of whoel grains!"<<endl;
            cout<<"Eat low glycemic index foods!"<<endl<<endl;
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;
            cout<<"Don't"<<endl;
            cout<<"_____" << endl ;
            cout<<"Eat starchy carbs!"<<endl;
            cout<<"Tolerate belly fat...you have belly fat if-"<<endl;
            if (sex=='M')
            {cout<<"your waist size is more than 45 inches!"<<endl<<endl;
            }
            else
            {cout<<"if your waist size is more than 40 inches!"<<endl<<endl;
            }
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
            cout<<"You're good to go!"<<endl;
            break ;

        case 'H' :
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_GREEN) ;
            cout<<"Do:"<<endl;
            cout<<"___"<<endl ;
            cout<<"Maintain a healthy weight!"<<endl;
            cout<<"Make sure to exercise regularly!"<<endl;
            cout<<"Reduce your salt intake!"<<endl<<endl;
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;
            cout<<"Don't"<<endl;
            cout<<"_____" << endl ;
            cout<<"Drink alcohol!"<<endl;
            cout<<"Be stressed... stay relaxed,stay healthy =)"<<endl<<endl;
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
            cout<<"You're good to go!"<<endl;
            break ;

        case 'T' :
             SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_GREEN) ;
            cout<<"Do:"<<endl;
            cout<<"___"<<endl ;
             cout<<"Drink juices of nutrient dense veggies!"<<endl;
             cout<<"Eat anti-inflammatory herbs like basil and rosemary!"<<endl;
             cout<<"Eat ginger to boost immune function!"<<endl<<endl;
             SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED) ;
            cout<<"Don't"<<endl;
            cout<<"_____" << endl ;
             cout<<"Eat processed foods!"<<endl;
             cout<<"Eat foods with artificial flavouring or sugar!"<<endl<<endl;
             SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
             cout<<"You're good to go!"<<endl;
             break ;

        case 'C' :
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_GREEN) ;
            cout<<"Do:"<<endl;
            cout<<"___"<<endl ;
            cout<<"Consume fibre-rich foods!"<<endl;
            cout<<"Choose protein-rich plant foods over meat!"<<endl;
            cout<<"Lose as much excess weight as possible... stay light,stay healthy!"<<endl<<endl;
            cout<<"Don't"<<endl;
            cout<<"Eat foods with saturated and trans fats!"<<endl;
            cout<<"Eat foods with dietary cholestrol!"<<endl<<endl;
            SetConsoleTextAttribute(handle,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN) ;
            cout<<"You're good to go!"<<endl;
            break ;

        default :
            cout<<"Eat a blanced meal every meal of the day!"<<endl;
            cout<<"Limit junk food to special occasions!"<<endl;
            cout<<"Exercise is important so clear out time from your schedule for it!"<<endl<<endl;
            cout<<"You're good to go!"<<endl;
            break ;

     }


}


int cal ()
{   int choice[5], cal(0),i(0), subchoice(0),roti(0),idli(0),jamun(0);

    COORD userinput ;
    userinput.X = 0;
    userinput.Y = 38;

    COORD menustart ;
    menustart.X = 0 ;
    menustart.Y = 18 ;

    COORD point ;
    point.X = 0 ;
    point.Y = 0 ;

    cout<< "Choose a meal"<<endl;
    cout << "1. Breakfast  \n2. Lunch  \n3. Dinner " ;
    SetConsoleCursorPosition(handle,userinput) ;
    cout << "Enter your choice: "  ;
    cin>> opt;
    switch(opt)
    {
      case 1 :
                SetConsoleCursorPosition(handle,menustart) ;
                cout << "What did you eat for breakfast? "<<endl;
                cout<< "[1]Cereal          [2]Bread        [3]Eggs    [4]Fruits  "<<endl ;
                cout <<"[5]Milk            [6]Coffee       [7]Tea     [8]End " << endl ;
                cout << "\nEnter five choices in a row, and press 8 to end " << endl;
                for ( i = 0 ; i < 5 ; i++)
                {
                    SetConsoleCursorPosition(handle,userinput) ;
                    cout << "Enter your choice: "  ;
                    cout << "> \b \b" ;
                    cin >> choice[i] ;
                    if (choice[i] == 1)
                    {
                        cal = cal + 234;

                        point.X = 1 ;
                        point.Y = 19 ;
                        cal = cal + 234;
                        SetConsoleCursorPosition(handle,point) ;
                        cout << "*" ;
                    }
                    else if (choice[i] == 2)
                    {
                        cal = cal + 230;

                        point.X = 20 ;
                        point.Y = 19 ;
                        SetConsoleCursorPosition(handle,point) ;
                        cout << "*" ;
                    }
                    else if (choice[i] == 3)
                    {
                        cal = cal + 150;

                        point.X = 36;
                        point.Y = 19 ;
                        SetConsoleCursorPosition(handle,point) ;
                        cout << "*" ;
                    }
                    else if (choice[i] == 4)
                    {
                        cal = cal + 345;

                        point.X = 47 ;
                        point.Y = 19 ;
                        SetConsoleCursorPosition(handle,point) ;
                        cout << "*" ;
                    }
                    else if (choice[i] == 5)
                    {
                        cal = cal + 65;

                        point.X = 1 ;
                        point.Y = 20 ;
                        SetConsoleCursorPosition(handle,point) ;
                        cout << "*" ;
                    }
                    else if (choice[i] == 6)
                    {
                        cal = cal + 40;

                        point.X = 20 ;
                        point.Y = 20 ;
                        SetConsoleCursorPosition(handle,point) ;
                        cout << "*" ;
                    }
                    else if (choice[i] == 7)
                    {
                        cal = cal + 30;

                        point.X = 36 ;
                        point.Y = 20 ;
                        SetConsoleCursorPosition(handle,point) ;
                        cout << "*" ;
                    }

                    if (choice[i] == 8 )
                        break;

                    while (choice[i] > 8 || choice[i] < 1)
                    {
                        cout << "Please enter a valid option!" << endl;

                        cin >> choice[i] ;
                    }


                }


                point.X = 0 ;
                point.Y = 23 ;
                SetConsoleCursorPosition(handle,point) ;
                cout << "Did your breakfast include butter/jam/chocolate or maple syrup?"<<endl;
                cout << " 1.Yes  2.No"<<endl;
                SetConsoleCursorPosition(handle,userinput) ;
                cout << "                          " ;
                SetConsoleCursorPosition(handle,userinput) ;
                cout << "Enter your choice: "  ;
                cin >> subchoice;
                if(subchoice == 1)
                 { cal = cal+37; }

                point.Y += 2;
                SetConsoleCursorPosition(handle,point) ;
                cout<<"How many glasses of water did you drink today? ";
                SetConsoleCursorPosition(handle,userinput) ;
                cout << "                          " ;
                SetConsoleCursorPosition(handle,userinput) ;
                cout << "Enter Number of glasses: " ;
                cin>> water;

                system("cls") ;
                header() ;

                cout << endl ;
                cout << setw(65) <<"Number of Calories consumed: " << cal << endl;
                break ;


        case 2 :
        case 3 :                                                                                    //Same options for lunch and dinner. Thus, we utilise the fall through feature of the switch case funstion.

              SetConsoleCursorPosition(handle,menustart) ;
              cout << "What did you eat? "<<endl;
              cout << " [1]Roti          [2]Idli        [3]Pulses "<<endl ;
              cout << " [4]Vegetables    [5]Rice        [6]Dosa" << endl;
              cout << " [7]Soup          [8]Egg         [9]Chicken" << endl ;
              cout << "[10]Mutton       [11]Prawns     [12]Fish" << endl ;
              cout << "\nEnter your 5 options, or press 13 to exit. " << endl;
              for ( i = 0 ; i < 5 ; i++)
                    {
                        SetConsoleCursorPosition(handle,userinput) ;
                        cout << "Enter your choice: "  ;
                        cout << ">  \b\b  \b\b" ;
                        cin >> choice[i] ;

                        switch (choice[i])
                        {
                            case 1 :
                                    point.X = 2 ;
                                    point.Y = 19 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 2 :
                                    point.X = 19 ;
                                    point.Y = 19 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 3 :
                                    point.X = 34 ;
                                    point.Y = 19 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 4 :
                                    point.X = 2 ;
                                    point.Y = 20 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 5 :
                                     point.X = 19;
                                     point.Y = 20 ;
                                     SetConsoleCursorPosition(handle,point) ;
                                     cout << "*" ;
                                     break ;
                            case 6 :
                                    point.X = 34 ;
                                    point.Y = 20 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 7 :
                                    point.X = 2 ;
                                    point.Y = 21 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 8 :
                                    point.X = 19 ;
                                    point.Y = 21 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 9 :
                                    point.X = 34 ;
                                    point.Y = 21 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                    break ;

                            case 10 :
                                    point.X = 0 ;
                                    point.Y = 22 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << " [*" ;
                                    break ;

                            case 11 :
                                    point.X = 17 ;
                                    point.Y = 22 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << " [*" ;
                                    break ;

                            case 12 :
                                    point.X = 32 ;
                                    point.Y = 22 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << " [*" ;
                                    break ;


                        }

                        if (choice[i] == 13 )
                            break;
                        while (choice[i] > 13 || choice[i] < 1)                                //To facilitate continuous and smooth input, we first recieve all the choices made by the user, store it in an array, then check the values.
                        {
                            cout << "Please enter a valid option!" << endl;
                            cin >> choice[i] ;
                        }
                    }

                for ( i = 0 ; i < 5 ; i++)
                {
                    if (choice[i]== 1)
                    {
                        point.X = 0 ;
                        point.Y = 26;
                        SetConsoleCursorPosition(handle,point) ;
                        cout<< "How many rotis did you have? ";

                        SetConsoleCursorPosition(handle,userinput) ;
                        cout << "Enter number of rotis consumed:  \b\b" ;
                        cin>> roti;
                        cal = cal + roti*110;
                    }

                    else if (choice[i]==2)
                    {
                        point.X = 0 ;
                        point.Y = 26;
                        SetConsoleCursorPosition(handle,point) ;
                        cout<< "How many idlis did you have? ";

                        SetConsoleCursorPosition(handle,userinput) ;
                        cout<< "Enter number of idlis consumed:  \b\b";
                        cin>> idli;
                        cal = cal + 51*idli;
                    }
                    else if (choice[i]==3)
                        cal = cal + 102;
                    else if (choice[i]==4)
                        {
                            point.X = 0 ;
                            point.Y = 26;
                            SetConsoleCursorPosition(handle,point) ;
                            cout << "          Which vegetables did you eat? " << endl ;
                            cout << "          [1]Lady Finger      [2]Cabbage      [3]Potato" << endl ;
                            cout << "          [4]Brinjal          [5]Beans        [6]Mushroom" << endl ;
                            cout << "          [7]Spinach          [8]Raddish      [9]End" << endl << endl ;
                            cout << "          Please enter 3 options, or 9 to end" << endl ;
                            for (int j=0; j<3; j++)

                            {
                                SetConsoleCursorPosition(handle,userinput) ;
                                cout << "                                          \r" ;
                                cout << "Enter your choice: "  ;
                                cout << ">  \b\b" ;

                                cin >> subchoice;
                                if (subchoice == 1)
                                {
                                    cal= cal + 33;
                                    point.X = 11 ;
                                    point.Y = 27 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==2)
                                {
                                    cal = cal + 25;
                                    point.X = 31 ;
                                    point.Y = 27 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==3)
                                {
                                    cal = cal + 77;
                                    point.X = 47 ;
                                    point.Y = 27 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==4)
                                {
                                   cal = cal + 25;
                                   point.X = 11 ;
                                    point.Y = 28 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==5)
                                {
                                    cal = cal + 347;
                                    point.X = 31 ;
                                    point.Y = 28 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==6)
                                {
                                    cal = cal + 22;
                                    point.X = 47 ;
                                    point.Y = 28 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==7)
                                {
                                    cal = cal + 23;
                                    point.X = 11 ;
                                    point.Y = 29 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==8)
                                {
                                    cal = cal + 16;
                                    point.X = 31 ;
                                    point.Y = 29 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "*" ;
                                }
                                else if (subchoice ==9)
                                {
                                    point.X = 0 ;
                                    point.Y = 26 ;
                                    SetConsoleCursorPosition(handle,point) ;
                                    cout << "                                                         " << endl ;
                                    cout << "                                                         " << endl ;
                                    cout << "                                                         " << endl ;
                                    cout << "                                                         " << endl ;
                                    cout << "                                                         " << endl ;
                                    cout << "                                                         " << endl ;
                                    break ;
                                }
                            }
                        }
                    else if (choice[i]==5)
                        cal = cal + 130;
                    else if (choice[i]==6)
                        cal = cal + 120;
                    else if (choice[i]==7)
                        cal = cal + 25;
                    else if (choice[i]==8)
                        cal = cal + 147;
                    else if (choice[i]==9)
                        cal = cal + 239;
                    else if (choice[i]==10)
                        cal = cal + 294;
                    else if (choice[i]==11)
                        cal = cal + 105;
                    else if (choice[i]==12)
                        cal = cal + 206;

                }


              /*cout << "Did you eat any dessert?"<<endl;
              cout << " 1.Yes  2.No"<<endl <<">";
              cin >> opt;
                        if(opt == 1)
                            { cout << "Please enter 3 options, or 7 to end." <<endl;
                              cout << "\n1.Ice-Cream     2.Gulab Jamun          3.Cake "<<endl;
                              cout <<   "4.Rasgulla      5.Caramel Custard      6.Custard" << endl ;
                              for (int k=0; k<3; k++)
                                {
                                    cout << ">" ;
                                    cin >> subchoice;
                                    if (subchoice== 1)
                                        cal= cal + 207;
                                    else if (subchoice==2)
                                        {   cout<< "How many gulab jamuns did you eat?";
                                            cin >> jamun;
                                            cal= cal + 142*jamun;

                                        }

                                    else if (subchoice== 3)
                                        cal= cal + 239;
                                    else if (subchoice==4)
                                        {   cout<< "How many rasgullas did you eat? ";
                                            cin>>jamun;
                                            cal= cal + 146*jamun;
                                        }
                                     else if (subchoice==5)
                                        cal= cal + 234;
                                     else if (subchoice==6)
                                        cal= cal + 122;
                                     else if (subchoice==7)
                                        break;
                                }
                            }*/

              point.X = 0 ;
              point.Y = 26 ;
              SetConsoleCursorPosition(handle,point) ;
              cout<<"How many glasses of water did you drink today? ";

              SetConsoleCursorPosition(handle,userinput) ;
              cout << "                          " ;
              SetConsoleCursorPosition(handle,userinput) ;
              cout << "Enter Number of glasses: " ;
              cin>> water;

              system("cls") ;
              header() ;
              cout << endl ;
              cout << setw(65) <<"Number of Calories consumed: " << cal << endl;
              return cal ;
              break ;

    }

    return 0 ;
}

void load()
{
    int i ;
    COORD pt ;
    pt.X = 43 ;
    pt.Y = 20 ;
    SetConsoleCursorPosition(handle,pt) ;
    cout << "INITIALISING." ;
        for(i = 0 ; i <= 300000000 ; i++) ; system("cls") ;                                    //time delay
    SetConsoleCursorPosition(handle,pt) ;
    cout << "INITIALISING ." ;
        for(i = 0 ; i <= 300000000 ; i++) ; system("cls") ;
    SetConsoleCursorPosition(handle,pt) ;
    cout << "INITIALISING  ." ;
        for(i = 0 ; i <= 300000000 ; i++) ; system("cls") ;
    pt.X = 39 ;
    SetConsoleCursorPosition(handle,pt) ;
    cout << "INITIALISATION COMPLETE" ;
        for(i = 0 ; i <= 500000000 ; i++) ;
    system("cls") ;


}






