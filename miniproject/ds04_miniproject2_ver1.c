 /*
  2   대여함수 구현 완료
  3   추가보완할 점:
  4   반납기능
  5   도서목록에서 대출여부까지 출력
  6 */
  7
  8 #include <stdio.h>
  9 #include <stdlib.h>
 10 #include <string.h>
 11
 12 #define MAX 256
 13
 14 typedef struct NODE {
 15   int index;
 16   int checkout;
 17   char* title;
 18   char* author;
 19   char* brand;
 20   char* price;
 21   struct NODE* next;
 22 }node;
 23
 24 // 도서 등록(구매)
 25 void book_add(node* pnode)
 26 {
 27   printf("\n----- 도서 등록 -----\n\n");
 28   char* intitle = malloc(MAX * sizeof(char));
 29   char* inauthor = malloc(MAX* sizeof(char));
 30   char* inbrand = malloc(MAX* sizeof(char));
 31   char* inprice = malloc(MAX* sizeof(char));
 32   static int inindex = 1;
 33   printf("책 제목 입력 >> ");
 34   scanf("%s", intitle);
 35   printf("책 저자 입력 >> ");
 36   scanf("%s", inauthor);
 37   printf("책 출판사 입력 >> ");
 38   scanf("%s", inbrand);
 39   printf("책 가격 입력 >> ");
 40   scanf("%s", inprice);
 41
 42   node* newNode = (node*)malloc(sizeof(node));
 43   newNode->title = intitle;
44   newNode->author = inauthor;
 45   newNode->brand = inbrand;
 46   newNode->price = inprice;
 47   newNode->checkout = 0;
 48   newNode->index = inindex++;
 49   newNode->next = NULL;
 50
 51   while(pnode->next !=NULL){
 52     pnode = pnode->next;
 53   }
 54   pnode->next = newNode;
 55
 56 }
 57
 58 // 도서 삭제
 59 void book_delete(node* pnode)
 60 {
 61   printf("\n----- 도서 삭제 -----\n\n");
 62   char intitle[MAX];/* = malloc(MAX*sizeof(char));*/
 63   printf("삭제 도서 제목 입력 >> ");
 64   scanf("%s", intitle);
 65
 66   node* curr = pnode;
 67   node* temp = NULL;
 68
 69   while(curr->next != NULL && strcmp(curr->next->title, intitle) != 0){
 70     curr = curr->next;
 71   }
 72
 73   if(curr->next != NULL) {
 74     temp = curr->next;
 75     curr->next = temp->next;
 76     free(temp->title);
 77     free(temp);
 78     printf("%s 도서를 삭제했습니다\n", intitle);
 79   }
 80
 81   else
 82     printf("도서를 찾을 수 없습니다\n");
 83
 84   //free(intitle);
 85 }
 86
 87 //도서 출력
 88 void book_list(node* pnode)
 89 {
 90   printf("\n----- 도서 목록 -----\n");
 91   node* curr;
 92   curr = pnode->next;
 93
 94   while(curr !=NULL){
 95     printf("\n[책번호] %d\n", curr->index);
 96     printf("[도서명] %s\n", curr->title);
 97     printf("[저  자] %s\n", curr->author);
 98     printf("[출판사] %s\n", curr->brand);
 99     printf("[가  격] %s원\n", curr->price);
100     curr = curr->next;
101   }
102 }
103
104 //제목 검색
105 void seach_Title(node* pnode)
106 {
107   printf("\n***** 제목 검색 *****\n");
108   char intitle[MAX];
109   printf("검색 도서 제목 입력 >> ");
110   scanf("%s", intitle);
111   node* curr;
112   curr = pnode->next;
113
114   while(curr !=NULL){
115     if(strcmp(curr->title, intitle) == 0){
116       printf("검색하신 도서 [%s]이(가) 있습니다\n", intitle);
117       break;
118     }
119     if(curr->next == NULL){
120       printf("도서 [%s]은(는) 목록에 없습니다\n", intitle);
121       break;
122     }
123     else
124       curr = curr->next;
125   }
126
127 }
129 //저자 검색
130 void seach_Author(node* pnode)
131 {
132   printf("\n***** 저자 검색 *****\n");
133   char inauthor[MAX];
134   printf("검색 도서 저자 입력 >> ");
135   scanf("%s", inauthor);
136   printf("\n");
137   node* curr;
138   curr = pnode->next;
139
140   while(curr !=NULL){
141     if(strcmp(curr->author, inauthor) == 0){
142       printf("[책번호] %d\n[도서명] %s\n[저  자] %s\n",curr->index, curr->title, inautho>
143       if(curr->next != NULL) {
144         curr = curr->next;
145         continue;
146       }
147       else break;
148     }
149     else {
150       if(curr->next == NULL){
151         printf("저자 %s의 도서는 목록에 없습니다\n", inauthor);
152         break;
153       }
154       else
155         curr = curr->next;
156     }
157   }
158 }
159
160 //출판사 검색
161 void seach_Brand(node* pnode)
162 {
163   printf("\n**** 출판사 검색 ****\n");
164   char inbrand[MAX];
165   printf("검색 도서 출판사 입력 >> ");
166   scanf("%s", inbrand);
167   node* curr;
168   curr = pnode->next;
169
170   while(curr != NULL){
171     if(strcmp(curr->brand, inbrand) == 0){
172       printf("\n[책번호] %d\n[도서명] %s\n[출판사] %s\n",curr->index, curr->title, inbra>
173       if(curr->next != NULL) {
174         curr = curr->next;
175         continue;
176       }
177       else break;
178     }
179     else{
180       if(curr->next == NULL){
181         printf("출판사 %s의 도서는 목록에 없습니다\n", inbrand);
182         break;
183       }
184       else
185         curr = curr->next;
186     }
187   }
188 }
189
190 //책대여
191 void book_checkout(node* pnode)
192 {
193   int inindex;
194   node* curr;
195   curr = pnode->next;
196   int yesno;
197   printf("\n[Yes(0) or No(1)]도서를 대출 하시겠습니까? >> ");
198   scanf("%d", &yesno);
199
200   if(yesno == 0){
201     printf("대출할 책번호 입력 >> ");
202     scanf("%d", &inindex);
203     while(curr != NULL){
204       if(curr->index == inindex){
205         printf("\n[책제목] %s",curr->title);
206         if(curr->checkout == 0){
207           printf(" -----> 대출 완료\n");
208           curr->checkout = 1;
209         }
210         else {
211           printf(" -----> 대출 불가(현재 대출중)\n");
212         }
213         break;
214       }
215       else
216         curr = curr->next;
217     }
218   }
219   else return;
220
221 }
222 // 메뉴 목록
223 void  menu()
224 {
225   printf("\n***** 메뉴 *****\n");
226   printf("1 도서구입(등록)\n2 도서검색\n3 도서삭제\n4 도서(목록)출력\n0 종료\n");
227   printf("****************\n");
228 }
229
230 // 메뉴 선택
231 int menuSelect ()
232 {
233   int num;
234   printf("\n메뉴 선택 >> ");
235   scanf("%d", &num);
236   return num;
237 }
238
239 // 검색 키워드 선택
240 int seachSelect()
241 {
242   int num;
243   printf("\n----- 도서 검색 -----\n\n");
244   printf("****** 검색 키워드 ******\n");
245   printf("[5]제목 [6]저자 [7]출판사\n");
246   printf("*************************\n");
247   printf("키워드 선택 >> ");
248   scanf("%d", &num);
249   return num;
250 }
251
252 // main
253 void main()
254 {
255   node * head = (node*)malloc(sizeof(node));
256   head->next = NULL;
257   printf("\n< 도서관리 프로그램 >\n");
258
259   menu();
260   while(1){
261     switch(menuSelect()){
262       case 1 :
263         book_add(head);
264         break;
265
266       case 2 :
267         switch(seachSelect()){
268           case 5 ://제목검색
269             seach_Title(head);
270             book_checkout(head);
271             break;
272           case 6 ://저자검색
273             seach_Author(head);
274             book_checkout(head);
275             break;
276           case 7 ://출판사검색
277             seach_Brand(head);
278             book_checkout(head);
279             break;
280         }
281         break;
282
283       case 3 :
284         book_delete(head);
285         break;
286
287       case 4 :
288         book_list(head);
289         break;
290
291       case 0 :
292         printf("프로그램이 종료됩니다\n");
293         exit(1);
294         break;
295
296       default:
297         printf("\n[경고] 올바른 메뉴(0~4)를 입력하세요\n");
298         menu();
299     }
300     continue;
301   }
302 }
303
304



