/*
 * BIT_MATH.h
 *
 * Created: 3/14/2024 10:53:03 AM
 *  Author: solo
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)     (reg |= (1<<bit))
#define CLR_BIT(reg,bit)     (reg &= ~(1<<bit))
#define TOGLE_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)     ((REG >> BIT)&1)






#endif /* BIT_MATH_H_ */