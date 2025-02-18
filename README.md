# =======================================================
# Programming Assignment 2 - Josephus Problem Variant
#                      ---------
#         Matthew Barnes - Advanced Data Structures
# =======================================================

This project implements the Josephus Problem using std::lists & std::vectors. 
The program simulates the elimination process and records performance data for different 
values of N and M (# of participants and # of elimination steps respectively). 


# Compiling and running
# ~~~~~~~~~~~~~~~~~~~~~~
1) Type 'make' into terminal
2) Type: ./TestListMyJosephus to run the list tests
3) Type: ./TestVectorMyJosephus to run vector tests


# ***********************
# Discussion Questions
# ***********************
# 1. (2 pts) Does machine processing power affect execution time?
        -Yes, machine processing power has an affect on execution time. The simulation involves repeatedly
        removing elements from lists and vectors and a faster CPU with better perfoamnce would absolutely
        result in lower execution times. 
# 2. (5 pts) Which performs better: std::list or std::vector? Under what conditions?#
        -std::list performs better with deletions. erase() is O(1) when given an iterator. 
        Removing an element within std::vector is O(N). However, accessing elemnts is quicker with
        vectors. They have an O(1) access time. List's require O(N) when accessing. 
        All in all, when N is large there are alot of eliminations, std::list is better. 
        If N is smaller or M is larger, std::vector perfoms slightly better. vectors have better cache locality. 
# 3. (3 pts) How does N impact runtime compared to M?
        -N impacts runtime exponentially. The elimination process obviously goes on until one destination remains and the # of deletions is O(N) for std::list and O(N^2) in worst case for std::vector. 
        M has an impact on runtime as well, but not as big as N's. 
        N is definitily the primary factor in driving runtime up for this program. 
