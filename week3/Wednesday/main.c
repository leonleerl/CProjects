#include <stdio.h>
#include "team.h"

int main(int argc, char *argv[])
{
    struct Team hawthorn = {
        "Hawthorn", // name
        22,         // gamesPlayed
        17,         // gamesWon
        5,          // gamesLost
        0,          // gamesDrawn
        2000,       // pointsFor
        1294,       // pointsAgainst
        154.59,     // percentage
        68          // premiershipPoints
    };

    // 更新结构体内容
    hawthorn.gamesPlayed += 1;
    hawthorn.gamesWon += 1;
    hawthorn.pointsFor += 80;
    hawthorn.pointsAgainst += 60;
    hawthorn.percentage = (float)hawthorn.pointsFor / hawthorn.pointsAgainst * 100;
    hawthorn.premiershipPoints += 4;

    // 获取并打印结构体内容
    printf("Team: %s\n", hawthorn.name);
    printf("Games Played: %d\n", hawthorn.gamesPlayed);
    printf("Games Won: %d\n", hawthorn.gamesWon);
    printf("Points For: %d\n", hawthorn.pointsFor);
    printf("Points Against: %d\n", hawthorn.pointsAgainst);
    printf("Percentage: %.2f%%\n", hawthorn.percentage);
    printf("Premiership Points: %d\n", hawthorn.premiershipPoints);

    return 0;
}
