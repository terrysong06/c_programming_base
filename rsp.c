#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"      // 나(User)
#define YELLOW  "\033[33m"      // 강조
#define CYAN    "\033[36m"      // 대진표 선
#define BOLD    "\033[1m"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

const char* names[] = {"나(User)", "컴1", "컴2", "컴3", "컴4", "컴5", "컴6", "컴7"};
char b[7][40]; // bracket_map 줄임표 (0-3: 8강승자, 4-5: 4강승자, 6: 우승자)

void get_colored_name(int idx, char* buffer) {
    if (idx == 0) sprintf(buffer, "%s%s%s", GREEN, names[idx], RESET);
    else sprintf(buffer, "%s", names[idx]);
}

void init_bracket() {
    for (int i = 0; i < 7; i++) strcpy(b[i], "  ?   ");
}

// 가로 방향(8 -> 4 -> 2) 대진표 출력
void display_horizontal_bracket() {
    system(CLEAR);
    char p[8][40];
    for(int i=0; i<8; i++) get_colored_name(i, p[i]);

    printf(BOLD YELLOW "==================== [ 가로형 실시간 대진표 ] ====================\n\n" RESET);
    printf("  [8강]          [4강]          [결승]          [우승]\n\n");

    printf(" %s ──┐\n", p[0]);
    printf("           ├── %s ──┐\n", b[0]);
    printf(" %s ──┘           │\n", p[1]);
    printf("                        ├── %s ──┐\n", b[4]);
    printf(" %s ──┐           │           │\n", p[2]);
    printf("           ├── %s ──┘           │\n", b[1]);
    printf(" %s ──┘                       │\n", p[3]);
    printf("                                    ├── " BOLD YELLOW "[ %s ]" RESET "\n", b[6]);
    printf(" %s ──┐                       │\n", p[4]);
    printf("           ├── %s ──┐           │\n", b[2]);
    printf(" %s ──┘           │           │\n", p[5]);
    printf("                        ├── %s ──┘\n", b[5]);
    printf(" %s ──┐           │\n", p[6]);
    printf("           ├── %s ──┘\n", b[3]);
    printf(" %s ──┘\n", p[7]);
    
    printf(BOLD "\n------------------------------------------------------------------\n" RESET);
}

int determine_winner(int h1, int h2) {
    if (h1 == h2) return 0;
    return ((h1 == 1 && h2 == 3) || (h1 == 2 && h2 == 1) || (h1 == 3 && h2 == 2)) ? 1 : 2;
}

int main() {
    int winners_idx[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int num_participants = 8;
    int map_ptr = 0;
    
    srand(time(NULL));
    init_bracket();

    while (num_participants > 1) {
        int next_winners[4];
        int win_count = 0;

        for (int i = 0; i < num_participants; i += 2) {
            display_horizontal_bracket();
            int p1 = winners_idx[i];
            int p2 = winners_idx[i+1];
            
            char n1[40], n2[40];
            get_colored_name(p1, n1);
            get_colored_name(p2, n2);

            printf("\n" BOLD ">> 현재 매치: %s VS %s" RESET "\n", n1, n2);

            while (1) {
                int h1, h2;
                if (p1 == 0) {
                    printf("선택 (1:가위, 2:바위, 3:보): ");
                    if(scanf("%d", &h1) != 1) { while(getchar() != '\n'); continue; }
                } else h1 = rand() % 3 + 1;
                h2 = rand() % 3 + 1;

                int res = determine_winner(h1, h2);
                if (res != 0) {
                    int w_idx = (res == 1) ? p1 : p2;
                    char w_name[40];
                    get_colored_name(w_idx, w_name);
                    
                    printf(BOLD YELLOW ">> [%s] 승리!!\n" RESET, w_name);
                    strcpy(b[map_ptr++], w_name);
                    next_winners[win_count++] = w_idx;
                    
                    printf("\n엔터를 누르면 다음 경기로...");
                    getchar(); if(p1 == 0) getchar();
                    break;
                }
                printf("\033[31m무승부! 다시 선택합니다.\033[0m\n");
            }
        }
        num_participants /= 2;
        for (int i = 0; i < num_participants; i++) winners_idx[i] = next_winners[i];
    }

    display_horizontal_bracket();
    printf(BOLD GREEN "\n[축하합니다!] 최종 우승자는 %s입니다!\n" RESET, b[6]);
    return 0;
}
