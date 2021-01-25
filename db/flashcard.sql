CREATE TABLE if not exists flashcard
(
    id      INTEGER NOT NULL,
    name    TEXT,
    averse  TEXT,
    reverse TEXT,
    tip     TEXT,
    PRIMARY KEY (id)
)
