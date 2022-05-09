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
        PolyNode* ans = new PolyNode();
        PolyNode* p = ans;
        while(poly1 && poly2){
            if(poly1->power == poly2->power){
                int coff = poly1->coefficient + poly2->coefficient;
                if(coff != 0){
                    PolyNode* node = new PolyNode(coff, poly1->power);
                    p->next = node;
                    p = p->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            else if(poly1->power > poly2->power){
                p->next = new PolyNode(poly1->coefficient, poly1->power);
                p = p->next;
                poly1 = poly1->next;
            }
            else{
                p->next = new PolyNode(poly2->coefficient, poly2->power);
                p = p->next;
                poly2 = poly2->next;
            }
        }
        
        if(poly1){
            p->next = poly1;
            p = p->next;
        }
        
        if(poly2){
            p->next = poly2;
            p = p->next;
        }
        
        return ans->next;
    }
};