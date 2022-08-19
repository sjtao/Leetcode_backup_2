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
        PolyNode* dummy = new PolyNode();
        PolyNode* p = dummy;
        while(poly1 && poly2){
            if(poly1->power == poly2->power){
                int cof = poly1->coefficient + poly2->coefficient;
                if(cof != 0){
                    p->next = new PolyNode(cof, poly1->power);
                    p = p->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            else if(poly1->power > poly2->power){
                p->next = poly1;
                p = p->next;
                poly1 = poly1->next;
            }
            else{
                p->next = poly2;
                p = p->next;
                poly2 = poly2->next;
            }
        }
        if(poly1) p->next = poly1;
        else p->next = poly2;
        return dummy->next;
    }
};