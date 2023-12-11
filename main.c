#include <stdio.h>
#include "raylib.h"

void search(int target,int left,int right);
int arr[10] = {9, 2, 1, 5, 6 ,3, 7, 8 ,4 ,0};
int key_position = 0;

int main() {


    ///stale
    const int width=600, height=400;
    int framecounter =0;


    ///

    ///zmienne uzyteczne
    int key_input=48;
    bool button_clicked = false;

    ///






    ///main container
    Rectangle main_view;
    main_view.x = 50;
    main_view.y= 25;
    main_view.width= 500;
    main_view.height = 350;

    Vector2 main_view_vector;
    main_view_vector.x=0;
    main_view_vector.y=0;
    /////


    ///INPUT
    Rectangle input;
    input.x = 250;
    input.y= 100;
    input.width= 75;
    input.height = 50;

    Vector2 input_vector;
    input_vector.x=0;
    input_vector.y=0;

    ////


    ///Button
    Rectangle button;
    button.x = 250;
    button.y= 200;
    button.width= 75;
    button.height = 50;

    Vector2 button_vector;
    button_vector.x=0;
    button_vector.y=0;



    InitWindow(width,height,"Binary Search gui");
    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(DARKGRAY);


        DrawRectanglePro(main_view,main_view_vector,0,LIME);


        DrawText("Napisz liczbe ktora chcesz znalezc ze zbioru liczb:",main_view.x+ 50,main_view.y+10,16,BLACK);
        DrawText("( 9 2 1 5 6 3 7 8 4 0 )",main_view.x+ 150,main_view.y+30,16,BLACK);


        DrawRectanglePro(input,input_vector,0,LIGHTGRAY);
        DrawText(TextFormat("%d",key_input-48),input.x+15,input.y,36,BLUE);

        DrawRectanglePro(button,button_vector,0,LIGHTGRAY);
        DrawText("Oblicz!",button.x+5,button.y+12,20,BLACK);



        if(CheckCollisionPointRec(GetMousePosition(),input)){
            DrawRectangleLines(input.x,input.y,input.width,input.height,PINK);

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            framecounter++;

            if((framecounter/1000) %2 == 0) DrawText("_",input.x,input.y+10,40,PINK);



            int key = GetCharPressed();

            while (key > 0) {
                if ((key >= 32) && (key <= 125) ) {
                        key_input=key;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                key_input='\0';
            }

        }else{
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            framecounter = 0;

        }

        if(CheckCollisionPointRec(GetMousePosition(),button)) {
            DrawRectangleLines(button.x, button.y, button.width, button.height, PINK);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                button_clicked = true;
            }
        }

        if(button_clicked){
            /// search
            search(key_input-48,0,9);
            DrawText(TextFormat("Znalazlem na pozycji: %d",key_position+1),button.x-50, button.y+75,16,BLACK);


        }
        EndDrawing();
    }
    return 0;
}


void search(int target,int left,int right){

    printf("left: %d, right: %d\n",left,right);
    if (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target) {
            key_position = middle;
            return;

        } else if (arr[middle] < target) {

            left = middle + 1;

        } else {
            right = middle - 1;

        }

        search(target, left, right);
    } else {
        int tmp = right;
        right = left;
        left = tmp;
    }
}