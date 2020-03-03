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

#ifdef CLOCK_SETUP
    #if (CLOCK_SETUP == 0)
        #define CORE_CLOCK 20971520u
        #define BUS_CLOCK  20971520u
    #elif (CLOCK_SETUP == 1)
        #define CORE_CLOCK 48000000u
        #define BUS_CLOCK  24000000u
    #elif (CLOCK_SETUP == 2)
        #define CORE_CLOCK 4000000u
        #define BUS_CLOCK  800000u
    #elif (CLOCK_SETUP == 3)
        #define CORE_CLOCK 4000000u
        #define BUS_CLOCK  1000000u
    #elif (CLOCK_SETUP == 4)
        #define CORE_CLOCK 48000000u
        #define BUS_CLOCK  24000000u
    #endif
#else
#define CORE_CLOCK 20971520u
#define BUS_CLOCK 20971520u
#endif // CLOCK_SETUP

#endif // COMMON_H