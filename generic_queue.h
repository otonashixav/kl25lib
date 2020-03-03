/**
 * https://github.com/otonashixav
 * 
 * Circular Queue
 * Generates a set of functions that operate on a queue struct, along with the
 * struct itself, given a set of parameters. Can be generated from gcc via
 *   gcc -D (definitions) -E (this file) -o (output file) or included in a .c
 * file directly if no header file is required.
 * The following are required: 
 *  QUEUE_TYPE: name of the struct used to represent a queue
 *  QUEUE_DATA_TYPE: type of data held in the queue
 *  QUEUE_MAX_SIZE: max size of the queue
 * The following are optional depending on usage:
 *  QUEUE_FUNCTION_PARAMS: if the data type is a function pointer, this can be
 *                         used to insert code after the data type e.g. 
 *                         the square bracketed: void (*data[)(void)]
 *  QUEUE_MAX_SIZE_TYPE: if the max size exceeds 256, define an adequate type here
 */

#ifndef QUEUE_TYPE
#error Generic queue definition missing name.
#endif

#ifndef QUEUE_DATA_TYPE
#error Generic queue definition missing type.
#endif

#ifndef QUEUE_FUNCTION_PARAMS
#define QUEUE_FUNCTION_PARAMS
#endif

#ifndef QUEUE_MAX_SIZE
#error Generic queue definition missing size.
#endif

#ifndef QUEUE_MAX_SIZE_TYPE
#define QUEUE_MAX_SIZE_TYPE unsigned int
#endif

#ifndef CONCAT
#define CONCAT(X, Y) X##Y
#endif

/**
 * A struct representing a queue object (without methods; we're coding in C)
 */
typedef struct QUEUE_TYPE {
    QUEUE_DATA_TYPE data[QUEUE_MAX_SIZE] QUEUE_FUNCTION_PARAMS; /**The contained data*/
    QUEUE_MAX_SIZE_TYPE head; /**The head of the queue*/
    QUEUE_MAX_SIZE_TYPE tail; /**The tail of the queue*/
    QUEUE_MAX_SIZE_TYPE size; /**The current size of the queue*/
} QUEUE_TYPE;

/**
 * Empties a queue completely
 * @param[in] queue  the queue to clear
 */
#define CLEAR(N) CONCAT(N, _clear)
void CLEAR(QUEUE_TYPE)(QUEUE_TYPE *queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}

/**
 * Returns whether the queue is empty
 * @param[in] queue  the queue to test
 * @return whether the queue is empty
 */
#define IS_EMPTY(N) CONCAT(N, _is_empty)
int IS_EMPTY(QUEUE_TYPE)(QUEUE_TYPE *queue) {
    return queue->size == 0;
}

/**
 * Returns whether the queue is full
 * @param[in] queue  the queue to test
 * @return whether the queue is full
 */
#define IS_FULL(N) CONCAT(N, _is_full)
int IS_FULL(QUEUE_TYPE)(QUEUE_TYPE *queue) {
    return queue->size == QUEUE_MAX_SIZE;
}

/**
 * Returns 0 on success and 1 on full queue
 * @param[in, out] queue   the queue to push to
 * @param[in, out] object  the object to push into the queue
 * @return 0 on success and 1 on full queue
 */
#define PUSH(N) CONCAT(N, _push)
int PUSH(QUEUE_TYPE) (QUEUE_TYPE *queue, QUEUE_DATA_TYPE object QUEUE_FUNCTION_PARAMS) {
    if (IS_FULL(QUEUE_TYPE)(queue)) {
        return 1;
    }
    queue->data[queue->tail++] = object;
    queue->tail %= QUEUE_MAX_SIZE;
    queue->size++;
    return 0;
}

/**
 * Returns 0 on success and 1 on empty queue. object is untouched if nothing was popped
 * @param[in, out] queue   the queue to pop from
 * @param[in, out] object  the location to pop to
 * @return 0 on success and 1 on empty queue
 */
#define POP(N) CONCAT(N, _pop)
int POP(QUEUE_TYPE)(QUEUE_TYPE *queue, QUEUE_DATA_TYPE* object QUEUE_FUNCTION_PARAMS) {
    if (IS_EMPTY(QUEUE_TYPE)(queue)) {
        return 1;
    }
    *object = queue->data[queue->head++];
    queue->head %= QUEUE_MAX_SIZE;
    queue->size--;
    return 0;
}

#undef QUEUE_TYPE
#undef QUEUE_DATA_TYPE
#undef QUEUE_FUNCTION_PARAMS
#undef QUEUE_MAX_SIZE
#undef QUEUE_MAX_SIZE_TYPE
