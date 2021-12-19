import qbs

CppApplication {
    consoleApplication: true
    files: [
        "ai.c",
        "ai.h",
        "conditions.c",
        "conditions.h",
        "gameboard.c",
        "gameboard.h",
        "main.c",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
