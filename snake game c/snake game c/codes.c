#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <SDL.h>
#include <SDL_timer.h>

#define BLOCK_WIDTH 50
#define BLOCK_HEIGHT 50

int lastx = -50, lasty = -50, current_direction = 0, width, height, score, difficulty;

struct snake_part
{
    struct snake_part* next;
    SDL_Rect* curr_part;
}head, * end_of_tail = &head;

SDL_Rect fruit;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect innerLine, obst1, obst2, obst3, obst4, obst5;

void spawn_fruit()
{
    int where_to_spawn = difficulty == 4 ? 0 : 1;   //special level, has diffrent mathematics

    srand(time(NULL));

    fruit.w = BLOCK_WIDTH, fruit.h = BLOCK_HEIGHT;
label:
    fruit.x = (rand() % ((width - BLOCK_WIDTH) / BLOCK_WIDTH)) * 50 + ((BLOCK_WIDTH / 2) * where_to_spawn);
    fruit.y = (rand() % ((height - BLOCK_HEIGHT) / BLOCK_HEIGHT)) * 50 + ((BLOCK_HEIGHT / 2) * where_to_spawn);

    if (end_of_tail == &head)
    {
        if (head.curr_part->x == fruit.x && head.curr_part->y == fruit.y)
            goto label;
    }
    else
    {
        struct snake_part* move = end_of_tail;
        while (move != 0)
        {
            if (move->curr_part->x == fruit.x && move->curr_part->y == fruit.y)
                goto label;
            move = move->next;
        }
    }
    if (difficulty == 3 && ((fruit.x == obst1.x && fruit.y == obst1.y) || (fruit.x == obst2.x && fruit.y == obst2.y) || (fruit.x == obst3.x && fruit.y == obst3.y) || (fruit.x == obst4.x && fruit.y == obst4.y)))
        goto label;
    if (difficulty == 4 && ((fruit.x >= obst1.x && fruit.y >= obst1.y && fruit.x <= (obst1.x + obst1.w) && fruit.y <= (obst1.y + obst1.h)) ||
                            (fruit.x >= obst2.x && fruit.y >= obst2.y && fruit.x <= (obst2.x + obst2.w) && fruit.y <= (obst2.y + obst2.h)) ||
                            (fruit.x >= obst3.x && fruit.y >= obst3.y && fruit.x <= (obst3.x + obst3.w) && fruit.y <= (obst3.y + obst3.h)) ||
                            (fruit.x >= obst4.x && fruit.y >= obst4.y && fruit.x <= (obst4.x + obst4.w) && fruit.y <= (obst4.y + obst4.h)) ||
                            (fruit.x >= obst5.x && fruit.y >= obst5.y && fruit.x <= (obst5.x + obst5.w) && fruit.y <= (obst5.y + obst5.h))))
                            goto label;
}

void draw_snake()
{
    SDL_Rect blue_part = { lastx, lasty, BLOCK_WIDTH, BLOCK_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 10, 255, 100, 255);
    SDL_RenderFillRect(renderer, &blue_part);
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &fruit);
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 180, 0, 0, 100);
    SDL_RenderFillRect(renderer, head.curr_part);
    SDL_RenderPresent(renderer);
}

void setup()
{
    head.curr_part = malloc(sizeof(SDL_Rect));
    if (difficulty == 4) head.curr_part->x = 0, head.curr_part->y = 0;
    else head.curr_part->x = 25, head.curr_part->y = 25;
    head.curr_part->w = BLOCK_WIDTH, head.curr_part->h = BLOCK_HEIGHT;
    head.next = 0;

    if (difficulty == 4) innerLine.x = 0, innerLine.y = 0, innerLine.w = width, innerLine.h = height;
    else innerLine.x = BLOCK_WIDTH / 2, innerLine.y = BLOCK_HEIGHT / 2, innerLine.w = width - BLOCK_WIDTH, innerLine.h = height - BLOCK_HEIGHT;

    window = SDL_CreateWindow("C Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!window) return;

    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderPresent(renderer);
    if (!renderer) return;

    SDL_SetRenderDrawColor(renderer, 10, 255, 100, 255);
    SDL_RenderFillRect(renderer, &innerLine);
    SDL_RenderPresent(renderer);

    if (difficulty == 3)
    {
        obst1.x = 275, obst1.y = 125, obst1.w = 50, obst1.h = 50;
        obst2.x = 275, obst2.y = 475, obst2.w = 50, obst2.h = 50;
        obst3.x = 925, obst3.y = 125, obst3.w = 50, obst3.h = 50;
        obst4.x = 925, obst4.y = 475, obst4.w = 50, obst4.h = 50;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, &obst1);
        SDL_RenderFillRect(renderer, &obst2);
        SDL_RenderFillRect(renderer, &obst3);
        SDL_RenderFillRect(renderer, &obst4);
    }
    else if (difficulty == 4)
    {
        obst1.x = 400, obst1.y = 0, obst1.w = BLOCK_WIDTH, obst1.h = height;
        obst2.x = 0, obst2.y = height / 2, obst2.w = 400, obst2.h = BLOCK_HEIGHT;
        obst3.x = 800, obst3.y = 0, obst3.w = BLOCK_WIDTH, obst3.h = 300;
        obst4.x = 800, obst4.y = 300, obst4.w = width - obst4.x, obst4.h = BLOCK_HEIGHT;
        obst5.x = 850, obst5.y = 0, obst5.w = width - obst5.x, obst5.h = BLOCK_HEIGHT;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, &obst1);
        SDL_RenderFillRect(renderer, &obst2);
        SDL_RenderFillRect(renderer, &obst3);
        SDL_RenderFillRect(renderer, &obst4);
        SDL_RenderFillRect(renderer, &obst5);
    }
    spawn_fruit();
    draw_snake();
}

int direction(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_LEFT:
            if (current_direction != 4 || end_of_tail == &head)
                current_direction = 2;
            break;
        case SDL_SCANCODE_RIGHT:
            if (current_direction != 2 || end_of_tail == &head)
                current_direction = 4;
            break;
        case SDL_SCANCODE_UP:
            if (current_direction != 3 || end_of_tail == &head)
                current_direction = 1;
            break;
        case SDL_SCANCODE_DOWN:
            if (current_direction != 1 || end_of_tail == &head)
                current_direction = 3;
            break;
        default:
            break;
        }

    }
    else if (event.type == SDL_QUIT) {
        puts("QUIT!");
        return 1;
    }
    return 0;
}

void move_tail()
{
    lastx = end_of_tail->curr_part->x, lasty = end_of_tail->curr_part->y;//when you add new part to the snake, lastx,lasty=lastx,lasty

    if (end_of_tail->next != 0) {
        struct snake_part* move = end_of_tail;
        while (move->next != 0)
        {
            move->curr_part->x = move->next->curr_part->x;
            move->curr_part->y = move->next->curr_part->y;
            move = move->next;
        }
    }

    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, head.curr_part);
    SDL_RenderPresent(renderer);//this normalize the color of the tail

    switch (current_direction) {
    case 1:
        head.curr_part->y -= BLOCK_HEIGHT;
        break;
    case 2:
        head.curr_part->x -= BLOCK_WIDTH;
        break;
    case 3:
        head.curr_part->y += BLOCK_HEIGHT;
        break;
    case 4:
        head.curr_part->x += BLOCK_WIDTH;
        break;
    }
}
void add_tail()
{
    struct snake_part* new_end = malloc(sizeof(struct snake_part));
    if (!new_end) return;
    new_end->curr_part = malloc(sizeof(SDL_Rect));
    if (!new_end->curr_part) return;
    new_end->curr_part->x = lastx, new_end->curr_part->y = lasty, new_end->curr_part->w = BLOCK_WIDTH, new_end->curr_part->h = BLOCK_HEIGHT;
    new_end->next = end_of_tail;
    end_of_tail = new_end;
}

enum bool{ ok, end } move_check_add()
{
    move_tail();

    if (difficulty == 4)
    {
        if (head.curr_part->x < 0) head.curr_part->x = width - BLOCK_WIDTH;
        else if (head.curr_part->x >= width) head.curr_part->x = 0;
        else if (head.curr_part->y < 0) head.curr_part->y = height - BLOCK_HEIGHT;
        else if (head.curr_part->y >= height) head.curr_part->y = 0;//teleportation
    }
    else if (head.curr_part->x < (BLOCK_WIDTH / 2) ||
        head.curr_part->x >= (width - BLOCK_WIDTH) ||
        head.curr_part->y < (BLOCK_HEIGHT / 2) ||
        head.curr_part->y >= (height - BLOCK_HEIGHT / 2))
        return end;//bump into the frame

    if (difficulty == 3 && ((head.curr_part->x == obst1.x && head.curr_part->y == obst1.y) ||
        (head.curr_part->x == obst2.x && head.curr_part->y == obst2.y) ||
        (head.curr_part->x == obst3.x && head.curr_part->y == obst3.y) ||
        (head.curr_part->x == obst4.x && head.curr_part->y == obst4.y)))
        return end;//bump into an obstacle
    if (difficulty == 4 && ((head.curr_part->x >= obst1.x && head.curr_part->y >= obst1.y && head.curr_part->x < (obst1.x + obst1.w) && head.curr_part->y < (obst1.y + obst1.h)) ||
        (head.curr_part->x >= obst2.x && head.curr_part->y >= obst2.y && head.curr_part->x < (obst2.x + obst2.w) && head.curr_part->y < (obst2.y + obst2.h)) ||
        (head.curr_part->x >= obst3.x && head.curr_part->y >= obst3.y && head.curr_part->x < (obst3.x + obst3.w) && head.curr_part->y < (obst3.y + obst3.h)) ||
        (head.curr_part->x >= obst4.x && head.curr_part->y >= obst4.y && head.curr_part->x < (obst4.x + obst4.w) && head.curr_part->y < (obst4.y + obst4.h)) ||
        (head.curr_part->x >= obst5.x && head.curr_part->y >= obst5.y && head.curr_part->x < (obst5.x + obst5.w) && head.curr_part->y < (obst5.y + obst5.h))))//<, a ne <= za da moje da e tochno na granicata
        return end;//bump into an wall

    if (end_of_tail->next != 0)
    {
        struct snake_part* check = end_of_tail;
        while (check->next != 0)
        {
            if (check->curr_part->x == head.curr_part->x && check->curr_part->y == head.curr_part->y) return end;
            check = check->next;
        }
    }//bump into a part of the tail


    if (head.curr_part->x == fruit.x && head.curr_part->y == fruit.y) {
        spawn_fruit();
        score += 10;
        add_tail();
    }// eat the apple

    return ok;
}

void free_mem()
{
    struct snake_part* free_mem = end_of_tail->next;
    while (end_of_tail->next != 0)
    {
        free(end_of_tail->curr_part);
        free(end_of_tail);
        end_of_tail = free_mem;
        free_mem = end_of_tail->next;
    }
    free(head.curr_part);
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    int sleep_time = 0;


    printf("Enter which difficulty do you want to play on:\n2 - medium\n");
    scanf("%d", &difficulty);

    //if (difficulty == 1) width = 1500, height = 800, sleep_time = 250;
    /*else*/ if (difficulty == 2) width = 1300, height = 700, sleep_time = 200;
    //else if (difficulty == 3) width = 1300, height = 700, sleep_time = 200;
    //else if (difficulty == 4) width = 1300, height = 800, sleep_time = 250;
    else
    {
        printf("Invalid input! Please try again!");
        exit(0);
    }

    setup();

    while (1) {

        Sleep(sleep_time);

        SDL_Event event;
        SDL_PollEvent(&event);

        if (direction(event)) break;

        if (move_check_add()) break;

        draw_snake();
    }
    //end:
    free_mem();

    SDL_DestroyWindow(window);
    SDL_RenderClear(renderer);
    SDL_Quit();

    printf("\nGAME OVER!\nYour score is: %d\n", score);

    return 0;
}