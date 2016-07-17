provider example {
    /* Start creating directory */
    probe unlink_file(char*);
    probe create_and_write_big(char*);
    probe create_and_write_small(char*);
};
