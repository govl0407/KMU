/*********************************************
 * 23학년도 1학기 기말 snake게임 과제
 * 5조
 ********************************************/
#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 21
#define MAP_HEIGHT 21

int x[100], y[100];
int growth_x, growth_y;
int growth_count;
int poison_count;
int gate_count;
int poison_x, poison_y;
int length;
int max_length = 10;
int speed;
int score;
int best_score = 0;
int last_score = 0;
int dir;
int key;
int gate_A[2];
int gate_B[2];
int out_A;
int out_B;
time_t start_time, now;
time_t growth_timer, poison_timer;

int clearScore;

void draw(int x, int y, const char* s);
char get_post(int x, int y);
void title(void);
void reset(void);
void draw_map(void);
void move(int dir);
void pause_game(void);
void game_over(void);
void growth(void);
void poison(void);
void interface_(void);
void gate(void);
////////////////////////////////main
int main() {
    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    curs_set(0);
    noecho();
    timeout(0);// init

    title();//print title

    while (1) {
        key = getch(); //get way

        usleep(speed * 2500); //tick

        switch (key) {
        case 'a':
        case 'd':
        case 'w':
        case 's':
            if ((dir == 'a' && key != 'd') || (dir == 'd' && key != 'a') || (dir == 'w' && key != 's') ||
                (dir == 's' && key != 'w')) // go oposite = game over
                dir = key;
            key = 0;

            break;
        case PAUSE:
            pause_game();
            break;
        case ESC:
            endwin();
            exit(0);
        }
        move(dir);

        interface_();//draw
    }

    endwin();
    return 0;
}

void move(int dir) {
    int i;
    char ch;
    time(&now);
    if ((int)difftime(now, growth_timer) >= 8) { // 5초 이상 growth가 먹히지 않았다면
        draw(MAP_X + growth_x, MAP_Y + growth_y, " "); // 기존 growth 위치 지우기
        draw(MAP_X + poison_x, MAP_Y + poison_y, " ");
        growth(); // 새로운 위치에 growth 생성
    }

    draw_map();

    draw(MAP_X + x[length - 1], MAP_Y + y[length - 1], " "); //한칸씩 snake 이동
    for (i = length - 1; i > 0; i--) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    draw(MAP_X + x[0], MAP_Y + y[0], "X");//head부분을 이동방향으로 이동
    if (dir == 'a') --x[0];
    if (dir == 'd') ++x[0];
    if (dir == 'w') --y[0];
    if (dir == 's') ++y[0];
    if (score >= 50 && gate_count >= 1 && growth_count >= 5)
        clearScore = 1;
    if (score >= 100 && gate_count >= 5 && growth_count > 15)
        clearScore = 2;
    ///////////////////////////////////////vaild check
    ch = get_post(MAP_X + x[i], MAP_Y + y[i]);//다음 head 위치의 문자열
    if (ch == 'Z')//head가 벽을 만나면 게임오버
        game_over();
    else if (ch == 'P') {//head가 poison을 만나면 1칸 줄어들고 점수를 10점 감점
        score -= 10;
        poison_count++;
        draw(MAP_X + growth_x, MAP_Y + growth_y, " ");//growth도 지우고 새로 그린다
        growth();//growth를 새로 그림
        draw(MAP_X + x[length - 2], MAP_Y + y[length - 2], " ");
        draw(MAP_X + x[length - 1], MAP_Y + y[length - 1], " ");
        length--;//snake를 한칸 줄여준다
        x[length - 1] = x[length - 2];
        y[length - 1] = y[length - 2];
    }
    else if (ch == 'A') {//head가 growth를 만나면 1칸 늘어나고 10점 증가
        score += 10;

        growth_count++;
        draw(MAP_X + poison_x, MAP_Y + poison_y, " ");//poison을 지우고 새로 그린다
        growth();
        length++;//snake 한칸 증가
        x[length - 1] = x[length - 2];
        y[length - 1] = y[length - 2];

        if ((length % 10) == 0) {
            max_length += 10;
        }
    }
    else if (ch == 'X') {//자기 몸에 부딪히면 게임오버
        game_over();
        return;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    draw(MAP_X + x[i], MAP_Y + y[i], "O");//이동한 위치에 head를 그림

    if (length < 3) { game_over(); }//길이가 3보다 작아지면 게임오버

    if (MAP_X + x[0] == gate_A[0] && MAP_Y + y[0] == gate_A[1])//head가 A게이트와 만날 때
    {
        gate_count++;
        x[0] = gate_B[0] - MAP_X;//head를 다른 게이트의 위치로 옮겨준다
        y[0] = gate_B[1] - MAP_Y;
        switch (out_B) { //나오는 게이트의 위치에 따라서 snake의 방향을 재설정
        case 0:
            dir = 'd';
            break;
        case 1:
            dir = 's';
            break;
        case 2:
            dir = 'a';
            break;
        case 3:
            dir = 'w';
            break;
        }
        gate();//게이트를 다시 그려줌
    }
    else if (MAP_X + x[0] == gate_B[0] && MAP_Y + y[0] == gate_B[1])//head가 B게이트와 만날 때
    {
        gate_count++;
        x[0] = gate_A[0] - MAP_X;
        y[0] = gate_A[1] - MAP_Y;
        switch (out_A) {
        case 0:
            dir = 'd';
            break;
        case 1:
            dir = 's';
            break;
        case 2:
            dir = 'a';
            break;
        case 3:
            dir = 'w';
            break;
        }
        gate();
    }

    if ((int)difftime(now, poison_timer) >= 8) { // 5초 이상 poison가 먹히지 않았다면
        draw(MAP_X + poison_x, MAP_Y + poison_y, " "); // 기존 poison 위치 지우기
        growth(); // 새로운 위치에 poison 생성
    }
}

char get_post(int x, int y) {// 맵에서 x,y 좌표의 문자열을 리턴
    move(y, x * 2);
    chtype ch = inch();
    char extractedChar = ch & A_CHARTEXT;
    refresh();
    return extractedChar;
}

void growth(void) {//growth 아이템을 맵에 그려줌
    int i;

    int growth_crush_on = 0;
    int r = 0;
    attron(COLOR_PAIR(6));
    draw(MAP_X, MAP_Y + MAP_HEIGHT, " YOUR SCORE: ");
    printw("%3d, LAST SCORE: %3d, BEST SCORE: %3d", score, last_score, best_score);
    attroff(COLOR_PAIR(6));

    while (1) {
        growth_crush_on = 0;
        srand((unsigned)time(NULL) + r);
        growth_x = (rand() % (MAP_WIDTH - 2)) + 1;
        growth_y = (rand() % (MAP_HEIGHT - 2)) + 1;
        poison_x = (rand() % (MAP_WIDTH - 2)) + 1;
        poison_y = (rand() % (MAP_HEIGHT - 2)) + 1;


        for (i = 0; i < length; i++) {
            if (growth_x == x[i] && growth_y == y[i] || poison_x == x[i] && poison_y == y[i]) {// growth, poison 두 점이 겹치면 다시그림
                growth_crush_on = 1;
                r++;
                break;
            }
        }
        if (growth_crush_on == 1) continue;

        draw(MAP_X + growth_x, MAP_Y + growth_y, "A");//growth는 A poison은 P로 그려줌
        draw(MAP_X + poison_x, MAP_Y + poison_y, "P");

        speed -= 3;
        break;
    }
    time(&growth_timer); // growth_timer에 현재 시간 저장
    time(&poison_timer); // poison_timer에 현재 시간 저장
}
void gate()//wall에 gate를 그려주는 함수
{
    int i;
    srand((unsigned)time(NULL));
    int k = rand() % 19 + 1;
    int j = rand() % 4;
    j = 1;
    switch (j) {//gate를 그릴 wall을 선택
    case 0:
        for (i = 0; i < k; i++) {}
        draw(MAP_X, MAP_Y + i, "G");
        gate_A[0] = MAP_X;
        gate_A[1] = MAP_Y + i;
        break;

    case 1:
        for (i = 0; i < k; i++) {}
        draw(MAP_X + i, MAP_Y, "G");
        gate_A[0] = MAP_X + i;
        gate_A[1] = MAP_Y;
        break;

    case 2:
        for (i = 0; i < k; i++) {};
        draw(MAP_X + MAP_WIDTH - 1, MAP_Y + i, "G");
        gate_A[0] = MAP_X + MAP_WIDTH - 1;
        gate_A[1] = MAP_Y + i;
        break;

    case 3:
        for (i = 0; i < k; i++) {};
        draw(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "G");
        gate_A[0] = MAP_X + i;
        gate_A[1] = MAP_Y + MAP_HEIGHT - 1;
        break;
    }
    out_A = j; // A게이트가 어느 wall에 있는지 저장
    i = rand() % 19 + 1;
    int d = rand() % 4;


    while (d == j) {// gate가 그려지지 않은 wall 선택
        d = rand() % 4;
    }
    d = 3;
    switch (d) {
    case 0:
        for (i = 0; i < k; i++) {}
        draw(MAP_X, MAP_Y + i, "G");
        gate_B[0] = MAP_X;
        gate_B[1] = MAP_Y + i;
        break;

    case 1:
        for (i = 0; i < k; i++) {}
        draw(MAP_X + i, MAP_Y, "G");
        gate_B[0] = MAP_X + i;
        gate_B[1] = MAP_Y;
        break;

    case 2:
        for (i = 0; i < k; i++) {};
        draw(MAP_X + MAP_WIDTH - 1, MAP_Y + i, "G");
        gate_B[0] = MAP_X + MAP_WIDTH - 1;
        gate_B[1] = MAP_Y + i;
        break;

    case 3:
        for (i = 0; i < k; i++) {};
        draw(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "G");
        gate_B[0] = MAP_X + i;
        gate_B[1] = MAP_Y + MAP_HEIGHT - 1;
        break;
    }
    out_B = d; //B게이트가 어느 wall에 있는지 저장
}

void draw(int x, int y, const char* s) { //x,y 에 문자열을 그려줌
    move(y, x * 2);
    addstr(s);
    refresh();
}

void title(void) { //메인 타이틀 화면
    int i, j;

    timeout(0);

    draw_map();
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) draw(j, i, " ");
    }
    attron(COLOR_PAIR(1));
    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|         S N A K E        |");
    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");

    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < PRESS ANY KEY TO START > ");

    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "   O a, d, w, s : Move   ");
    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   O ESC : Quit             ");

    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17, "  Snake Game");
    attroff(COLOR_PAIR(1));

    while (1) {
        key = getch();
        if (key == ERR) {
            draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < PRESS ANY KEY TO START > ");
            usleep(400000);
            draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "                             ");
            usleep(400000);
        }
        else {
            if (key == ESC) {
                endwin();
                exit(0);
            }
            else {
                break;
            }
        }
    }
    reset();
}

void reset(void) {//게임 초기화
    int i;
    clear();
    draw_map();

    timeout(0);

    dir = 'a';
    speed = 130;
    length = 5;
    score = 0;
    time(&start_time);
    for (i = 0; i < length; i++) {
        x[i] = MAP_WIDTH / 2 + i;
        y[i] = MAP_HEIGHT / 2;
        draw(MAP_X + x[i], MAP_Y + y[i], "A");
    }
    draw(MAP_X + x[0], MAP_Y + y[0], "K");
    growth();
    gate();
}

void draw_map(void) {//맵과 벽 게이트를 그려주는 함수
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        draw(MAP_X + i, MAP_Y, "Z");
    }
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
        draw(MAP_X, i, "Z");
        draw(MAP_X + MAP_WIDTH - 1, i, "Z");
    }
    for (i = 0; i < MAP_WIDTH; i++) {
        draw(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "Z");
    }
    /////////////////////////////////////////////////////////////////
    if (clearScore == 1)
    {
        for (i = 5 + MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 6; i++) {//세로
            draw(MAP_X + MAP_WIDTH / 2, i, "Z");
        }
        for (i = 5; i < MAP_WIDTH - 5; i++) {//가로
            draw(MAP_X + i, MAP_Y + MAP_HEIGHT / 2, "Z");
        }
    }
    if (clearScore == 2)
    {
        for (i = 5 + MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 6; i++) {//세로
            draw(MAP_X + MAP_WIDTH / 2, i, "Z");
        }
        for (i = 4; i < 7; i++) {//가로
            draw(MAP_X + i, MAP_Y + 4, "Z");
            draw(MAP_X + i, MAP_Y + MAP_HEIGHT - 4, "Z");
        }
        for (i = 14; i < 17; i++) {//가로
            draw(MAP_X + i, MAP_Y + 4, "Z");
            draw(MAP_X + i, MAP_Y + MAP_HEIGHT - 4, "Z");
        }
    }
    attron(COLOR_PAIR(1));
    draw(gate_A[0], gate_A[1], "G");
    draw(gate_B[0], gate_B[1], "G");
    attroff(COLOR_PAIR(1));

}


void pause_game(void) {
    while (1) {
        key = getch();
        if (key == PAUSE) {
            draw(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
            usleep(400000);
            draw(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "                                    ");
            usleep(400000);
        }
        else {
            draw_map();
            refresh();
            return;
        }
    }
}

void game_over(void) { //게임이 종료되었을 때의 출력
    attron(COLOR_PAIR(1));
    draw(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    draw(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      GAME OVER..     |");
    draw(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    draw(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " YOUR SCORE : ");
    printw("%d", last_score = score);

    draw(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, " Press any keys to restart.. ");
    attroff(COLOR_PAIR(1));
    if (score > best_score) {
        best_score = score;
        draw(MAP_X + (MAP_WIDTH / 2) - 4, MAP_Y + 10, "W BEST SCORE W");
    }
    usleep(500000);
    growth_count = 0;
    poison_count = 0;
    gate_count = 0;
    timeout(0);
    clearScore = 0;
    getch();
    title();
}


void interface_(void) {
    time(&now);
    int elapsed_time = (int)difftime(now, start_time);
    attron(COLOR_PAIR(5));
    draw(MAP_X + MAP_WIDTH + 1, MAP_Y, "=== Score Board===\n");
    draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 1, "Length = ");
    printw("%2d, MAX =  %2d", length, max_length);
    draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 2, "Growth = ");
    printw("%2d", growth_count);
    draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 3, "Poison = ");
    printw("%2d", poison_count);
    draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 4, "Gate = ");
    printw("%2d", gate_count);
    draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 5, "Time(sec) = ");
    printw("%2d", elapsed_time);
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(3));
    draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 9, "=== Mission ===\n");
    if (clearScore == 0) {
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 10, "Goal Score = ");
        if (score >= 50) {
            printw("50 (V)");
        }
        else {
            printw("50 ( )");
        }
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 11, "Goal Growth = ");
        if (growth_count >= 5) {
            printw("5 (V)");
        }
        else {
            printw("5 ( )");
        }
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 12, "Goal Poison = ");
        if (poison_count >= 2) {
            printw("2 (V)");

        }
        else {
            printw("2 ( )");
        }
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 13, "Goal Gate = ");
        if (gate_count >= 1) {
            printw("1 (V)");
        }
        else {
            printw("1 ( )");
        }
        attroff(COLOR_PAIR(3));
    }

    if (clearScore == 1) {
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 10, "Goal Score = ");
        if (score >= 100) {
            printw("100 (V)");
        }
        else {
            printw("100 ( )");
        }
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 11, "Goal Growth = ");
        if (growth_count >= 5) {
            printw("15 (V)");
        }
        else {
            printw("15 ( )");
        }
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 12, "Goal Poison = ");
        if (poison_count >= 2) {
            printw("5 (V)");

        }
        else {
            printw("5 ( )");
        }
        draw(MAP_X + MAP_WIDTH + 1, MAP_Y + 13, "Goal Gate = ");
        if (gate_count >= 1) {
            printw("5 (V)");
        }
        else {
            printw("5 ( )");
        }
        attroff(COLOR_PAIR(3));
    }
}