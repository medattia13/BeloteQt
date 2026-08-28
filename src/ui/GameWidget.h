┌─────────────────────────────────────────────┐
│ Team 1: 87                         Team 2: 65│
│                                             │
│                  Player 2                   │
│                 [K♥] [9♣]                  │
│                                             │
│                                             │
│        [10♠]        [A♥]        [7♥]       │
│                                             │
│                                             │
│                  YOU                        │
│                                             │
│ [7♣] [8♣] [J♦] [Q♦] [K♠] [A♠] [9♥] [10♥] │
│                                             │
└─────────────────────────────────────────────┘
You could use a QGraphicsView/QGraphicsScene for this.

For a card game, I actually recommend:

QGraphicsView + QGraphicsScene

rather than trying to construct the whole table with hundreds of QPushButtons.
