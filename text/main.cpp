#include "text.h"

int main()
{
    char fileName[100];
    cout<<"which file do you want to open?"<<" ";
    cin>>fileName;
    file.open(fileName ,  fstream::in | fstream::out | fstream::app);
    if (!file )
      {
        cout << "This is a new file. I created it for you."<<endl;

        file.open(fileName,  fstream::in | fstream::out | fstream::trunc);
        file <<"\n";

      }
      else
      {    // use existing file
         cout<<"This File "<<fileName<< " Already Exists.\n";

      }


      loadFile(token,file);


}
