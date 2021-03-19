pthread_mutex_t name; // global

pthread_mutex_init(&name, NULL); // before threads initializiation
pthread_mutex_destroy(&name); // at the end of threads

pthread_mutex_lock(&name); // before pthread_exit BEGINNING OF A METHOD
pthread_mutex_unlock(&name); // AT THE END OF A METHOD

