#include <iostream>
#include <string>

using namespace std;

string Hexa (string binary)
{  string hexa ="";
	for (int i=0;i<binary.length()-3;i+=4)
{  string n = binary.substr(i,4);
	if(n=="0000")
		hexa.append("0");
	else if(n=="0001")
		hexa.append("1");
	else if(n=="0010")
		hexa.append("2");
	else if(n=="0011")
		hexa.append("3");
	else if(n=="0100")
		hexa.append("4");
	else if(n=="0101")
		hexa.append("5");
	else if(n=="0110")
		hexa.append("6");
	else if(n=="0111")
		hexa.append("7");
	else if(n=="1000")
		hexa.append("8");
	else if(n=="1001")
		hexa.append("9");
	else if(n=="1010")
		hexa.append("A");
	else if(n=="1011")
		hexa.append("B");
	else if(n=="1100")
		hexa.append("C");
	else if(n=="1101")
		hexa.append("D");
	else if(n=="1110")
		hexa.append("E");
	else if(n=="1111")
		hexa.append("F");

}
	return hexa;
}

int main()
{
    string key_input="";
    string left_out;
    string right_out;

    string key_output2;

    int pc1[56]={ 57, 49, 41, 33, 25, 17,
                  9, 1, 58, 50, 42, 34, 26,
                  18, 10, 2, 59, 51, 43, 35,
                  27, 19, 11, 3, 60, 52, 44,
                  36, 63, 55, 47, 39, 31, 23,
                  15, 7, 62, 54, 46, 38, 30,
                  22, 14, 6, 61, 53, 45, 37,
                  29, 21, 13, 5, 28, 20, 12, 4};

    int pc2[48]={ 14, 17, 11, 24, 1, 5,
                  3, 28, 15, 6, 21, 10,
                  23, 19, 12, 4, 26, 8,
                  16, 7, 27, 20, 13, 2,
                  41, 52, 31, 37, 47, 55,
                  30, 40, 51, 45, 33, 48,
                  44, 49, 39, 56, 34, 53,
                  46, 42, 50, 36, 29, 32};

    cin>>hex>>key_input;
    string key_output1;

    for(int i=0;i<=key_input.length();i++){
        switch(key_input[i]){
    case'0':
         key_output1.append("0000"); break;
        case '1':
            key_output1.append("0001"); break;
        case '2':
            key_output1.append("0010"); break;
        case '3':
            key_output1.append("0011"); break;
        case '4':
            key_output1.append("0100"); break;
        case '5':
           key_output1.append("0101"); break;
        case '6':
            key_output1.append("0110"); break;
        case '7':
            key_output1.append("0111"); break;
        case '8':
           key_output1.append("1000"); break;
        case '9':
            key_output1.append("1001"); break;
        case 'A':
            key_output1.append("1010"); break;
        case 'B':
            key_output1.append("1011"); break;
        case 'C':
            key_output1.append("1100"); break;
        case 'D':
            key_output1.append("1101"); break;
        case 'E':
            key_output1.append("1110"); break;
        case 'F':
            key_output1.append("1111"); break;

        }
    }

    string output[16];

    for(int i=0;i<56;i++){
        int index=pc1[i]-1;
        key_output2+=key_output1[index];

    }

    for(int i=0;i<=key_output2.length();i++)
    {
        if(i<28){
            left_out+=key_output2[i];
        }
        else if (i>=28){
            right_out+=key_output2[i];
        }
    }

    string temp_left=left_out;
    string temp_right=right_out;
    for(int round=0;round<16;round++){
       if(round==0||round==1||round==8||round==15){
     
            string last=temp_left.substr(0,1);
            string shifted=temp_left.substr(1,27);
            string left=shifted+last;
            temp_left=left;
            string last2=temp_right.substr(0,1);
            string shifted2=temp_right.substr(1,27);
            string right=shifted2+last2;
            temp_right=right;
            output[round]=left+right;

            }
            else
            {
            string last=temp_left.substr(0,2);
            string shifted=temp_left.substr(2,26);
            string left=shifted+last;
            temp_left=left;
            string last2=temp_right.substr(0,2);
            string shifted2=temp_right.substr(2,26);
            string right=shifted2+last2;
            temp_right=right;
            output[round]=left+right;

            }

           string pc2_output;
           for(int k=0;k<48;k++){
           int index2=pc2[k]-1;
           pc2_output+=output[round][index2];
           }
           output[round]=Hexa(pc2_output);
           cout<<output[round]<<endl;



          }



    return 0;

}