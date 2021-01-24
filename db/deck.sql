CREATE TABLE if not exists deck
(
    id          INTEGER NOT NULL,
    name        TEXT    NOT NULL,
    description TEXT,
    owner_id    INTEGER DEFAULT 0,
    public      INTEGER DEFAULT 0,
    tag         TEXT,
    PRIMARY KEY (id)
)
