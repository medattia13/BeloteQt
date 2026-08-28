MainWindow
│
├── Menu
│   ├── New Game
│   ├── Restart
│   └── Quit
│
└── GameWidget
MainWindow should mostly be the application shell.
You could eventually have:
MainWindow
│
├── StartScreen
│
├── GameWidget
│
├── SettingsWidget
│
└── ResultsWidget
