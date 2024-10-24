#ifndef mAnalysis_H
#define mAnalysis_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

size_t malloc_size = 0, free_size = 0;

#ifdef _WIN32
#define get_malloc_size _msize
#else
#define get_malloc_size malloc_usable_size
#endif

void *smalloc(size_t size)
{
    void *ret;

    ret = malloc(size);

    malloc_size += get_malloc_size(ret);

    return ret;
}

void sfree(void *ptr)
{
    free_size += get_malloc_size(ptr);

    free(ptr);

    return;
}

void m_analysis(void)
{
    fprintf(stderr, "== Malloc Analysis==\nalloc: %lld.\nfree: %lld.\nunfree %lld.\n", malloc_size, free_size, malloc_size - free_size);

    return;
}

#endif