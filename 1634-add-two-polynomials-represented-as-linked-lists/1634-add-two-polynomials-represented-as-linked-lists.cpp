/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        if(!poly1 && !poly2) return NULL;
        if(!poly1 && poly2) return poly2;
        if(poly1 && !poly2) return poly1;
        
        if(poly1->power == poly2->power){
            poly1->coefficient += poly2->coefficient;
            if(poly1->coefficient == 0)
                return addPoly(poly1->next, poly2->next);
            poly1->next = addPoly(poly1->next, poly2->next);
            return poly1;
        }
        else if(poly1->power > poly2->power){
            PolyNode* temp1 =  poly1->next;
            poly1->next = addPoly(temp1, poly2);
            return poly1;
        }
        else{
            PolyNode* temp2 =  poly2->next;
            poly2->next = addPoly(poly1, temp2);
            return poly2;
        }
        
    }
};