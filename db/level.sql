CREATE TABLE if not exists level
(
    id               INTEGER NOT NULL,
    name             TEXT    NOT NULL,
    repeat_frequency INTEGER DEFAULT 3600,
    PRIMARY KEY (id)
)