CREATE TABLE if not exists deckFlashcard
(
    id           INTEGER NOT NULL,
    deck_id      INTEGER NOT NULL,
    flashcard_id INTEGER NOT NULL,
    level_id     INTEGER NOT NULL,
    bad_answers  INTEGER DEFAULT 0,
    good_answers INTEGER DEFAULT 0,
    PRIMARY KEY (id),
    FOREIGN KEY (deck_id)
        REFERENCES deck (id)
        ON DELETE SET NULL
        ON UPDATE no action,
    FOREIGN KEY (flashcard_id)
        REFERENCES flashcard (id)
        ON DELETE SET NULL
        ON UPDATE no action,
    FOREIGN KEY (level_id)
        REFERENCES level (id)
        ON DELETE SET NULL
        ON UPDATE no action
)
