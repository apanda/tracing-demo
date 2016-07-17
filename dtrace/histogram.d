BEGIN {
    self->action = "";
}
example$target:::unlink_file {
    self->action="unlink_file";
}

example$target:::create_and_write_big {
    self->action="write_big";
}

example$target:::create_and_write_small {
    self->action="write_small"
}

syscall:*:write:entry 
/ pid == $target /
{ 
    @[self->action] = count();
}

