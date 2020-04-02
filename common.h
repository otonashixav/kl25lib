#ifndef COMMON_H
#define COMMON_H

#define MASK(X) (1 << (X))

#define CONCAT(X, Y) X ## Y

// IRQ-related macros
#define IRQN(IRQ) CONCAT(IRQ, n)
#define IRQHANDLER(IRQ) CONCAT(IRQ, Handler)
/** 
 * Since pending IRQs must be cleared when the IRQ triggers,
 * combine it into a single macro.
 */ 
#define IRQ(IRQ, EXEC) \
void IRQHANDLER(IRQ)(void) {\
    NVIC_ClearPendingIRQ(IRQN(IRQ));\
    EXEC;\
}

/**
 * Since priority must always be set and pending IRQs cleared
 * before enabling the IRQ, combine it into a single macro.
 */
#define ENABLE_IRQ(IRQ, PRIORITY) \
{\
    NVIC_SetPriority(IRQN(IRQ), PRIORITY);\
    NVIC_ClearPendingIRQ(IRQN(IRQ));\
    NVIC_EnableIRQ(IRQN(IRQ));\
}

#endif // COMMON_H
