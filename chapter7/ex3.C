#include <iostream>
using namespace std;

struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void Display(const box object);
void SetVolume(box * object);
int main(){
    box onebox = {"boxmaker",12.0,12.0,12.0};
    SetVolume(&onebox);
    Display(onebox);
    return 0;
}

void Display(const box object){
     cout << "maker: " << object.maker << endl;
     cout << "height: " << object.height << endl;
     cout << "width: " << object.width << endl;
     cout << "length: " << object.length << endl;
     cout << "volume: " << object.volume << endl;
}

void SetVolume(box * object){
     object->volume = object->height * object->width * object->length;
}


