#include <QtTest>

#include "../src/model/Team.h"

class TestTeam : public QObject
{
    Q_OBJECT

private slots:
    void createsTeam();
    void startsWithZeroScore();

    void storesPlayers();

    void addPoints();
    void addPointsMultipleTimes();

    void scoreIsIndependentBetweenTeams();
};

void TestTeam::createsTeam()
{
    Team team(1, 2);

    QCOMPARE(team.player1(), 1);
    QCOMPARE(team.player2(), 2);
}

void TestTeam::startsWithZeroScore()
{
    Team team(1, 2);

    QCOMPARE(team.score(), 0);
}

void TestTeam::storesPlayers()
{
    Team team(5, 8);

    QCOMPARE(team.player1(), 5);
    QCOMPARE(team.player2(), 8);
}

void TestTeam::addPoints()
{
    Team team(1, 2);

    team.addPoints(20);

    QCOMPARE(team.score(), 20);
}

void TestTeam::addPointsMultipleTimes()
{
    Team team(1, 2);

    team.addPoints(10);
    team.addPoints(20);
    team.addPoints(15);

    QCOMPARE(team.score(), 45);
}

void TestTeam::scoreIsIndependentBetweenTeams()
{
    Team team1(1, 2);
    Team team2(3, 4);

    team1.addPoints(30);

    QCOMPARE(team1.score(), 30);
    QCOMPARE(team2.score(), 0);
}

QTEST_MAIN(TestTeam)

#include "tst_team.moc"
