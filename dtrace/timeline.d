syscall:*:write:entry { 
    printf("%d write", timestamp); 
}

syscall:*:unlink:entry {
    printf("%d unlink", timestamp);
}

example$target:::unlink_file {
    printf("%d example unlink_file %s", timestamp, copyinstr(arg0));
}

example$target:::create_and_write_big {
    printf("%d example create_and_write_big %s", timestamp, copyinstr(arg0));
}

example$target:::create_and_write_small {
    printf("%d example create_and_write_small %s", timestamp, copyinstr(arg0));
}
