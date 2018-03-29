//
//  Words.h
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#ifndef __Q2__Words__
#define __Q2__Words__

#include <stdio.h>
struct Words{
    unsigned int count; // Number of words currently in list
    unsigned int capacity; // The total size allocated to the list.
    char **list; // The list storing the words
};

#endif /* defined(__Words__) */
