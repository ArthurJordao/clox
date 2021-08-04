#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
  chunk->count = 0;
  chunk->capactiy = 0;
  chunk->code = NULL;
}

void writeChunk(Chunk* chunk, uint8_t byte) {
  if (chunk->capactiy < chunk->count + 1) {
    int oldCapactiy = chunk->capactiy;
    chunk->capactiy = GROW_CAPACITY(oldCapactiy);
    chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapactiy, chunk->capactiy);
  }

  chunk->code[chunk->count] = byte;
  chunk->count++;
}

void freeChunk(Chunk* chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capactiy);
  initChunk(chunk);
}
