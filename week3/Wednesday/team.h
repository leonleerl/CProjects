

#define TEAM_H

struct Team
{
    char name[30];         // 队伍名称
    int gamesPlayed;       // 比赛场次
    int gamesWon;          // 赢场数
    int gamesLost;         // 输场数
    int gamesDrawn;        // 平局数
    int pointsFor;         // 总得分
    int pointsAgainst;     // 被对手得分
    float percentage;      // 百分比
    int premiershipPoints; // 联赛积分
};
