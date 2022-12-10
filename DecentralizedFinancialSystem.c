#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int w, q, z = 0;

struct {
    int nonce;
    int blockhash;
    int prev_blockhash;
    int balance;
    int pincode;
    int bal;
    int temp_pincode;
    int temp_balance;
    int sender;
    int reciever;
}add, get, check, upd, deposit, withdraw, temp, last;

void delay(int n){
    for(int i = 0; i < n; i++){
        
    }
}

void blocks(){
    system("cls");
    system("color 3");

    FILE *fptr, *t;
    fptr = fopen("block.dat", "r");
    t = fopen("transaction.dat", "r");

    int l = 0;

    while(fscanf(t, "%d %d %d", &temp.sender, &temp.reciever, &temp.balance) != EOF){
        l++;
    }
    fclose(t);

    int a[l], b[l], c[l];
    int j = 0;

    FILE *t1;
    t1 = fopen("transaction.dat", "r");

    while(fscanf(t1, "%d %d %d", &upd.sender, &upd.reciever, &upd.balance) != EOF){
        a[j] = upd.sender, b[j] = upd.reciever, c[j] = upd.balance;
        j++;
    }

    int e, i = 0, n = 0, y;

    while(fscanf(fptr, "%d %d %d", &get.nonce, &get.blockhash, &get.prev_blockhash) != EOF){
        printf("Block %d", i);
        for(y = n; y < l; y++){
            if(a[y] == 0){
                printf("\n\t{\n\t\tsender: bank\n\t\treciever: %d\n\t\tamount: %d\n\t}", b[y], c[y]);    
            }
            else{
                printf("\n\t{\n\t\tsender: %d\n\t\treciever: %d\n\t\tamount: %d\n\t}", a[y], b[y], c[y]);
            }
            if(y == n + 2){
                break;
            }
        }
        n = y + 1;
        printf("\n\tnonce: %d\n\tblock hash: %d\n\tprevious block hash: %d\n\t", get.nonce, get.blockhash, get.prev_blockhash);
        e = 1;
        i++;
        printf("\n\n");
    }

    fclose(fptr);
    fclose(t1);

    if(e == 1){
        printf("\n\n\n1. Return to the dashboard");
        printf("\n2. Return to nodes");
        printf("\n\n3. Close the program");
        printf("\n\n\n\n\nSelect the desire opton: ");
        scanf("%d", &e);

        switch(e){
            case 1:
                dashboard();
                break;
            case 2:
                nodes();
                break;
            case 3:
                close();
                break;
        }
    }
}

int gen_nonce(){
    FILE *fptr;
    fptr = fopen("nonce.dat", "r");

    while(fscanf(fptr, "%d", &get.nonce) != EOF){
        add.nonce = get.nonce;
    }

    fclose(fptr);

    FILE *ptr;
    ptr = fopen("nonce.dat", "w");

    fprintf(ptr, "%d", add.nonce + 1);
    fclose(ptr);

    return get.nonce;
}

int prev_blockhash(){
    FILE *fptr;
    fptr = fopen("prev_hash.dat", "r");

    while(fscanf(fptr, "%d", &get.prev_blockhash) != EOF){
        add.prev_blockhash = get.prev_blockhash;
    }

    fclose(fptr);

    return add.prev_blockhash;
}

int gen_blockhash(){
    FILE *fptr;
    fptr = fopen("blockhash.dat", "r");

    while(fscanf(fptr, "%d", &get.blockhash) != EOF){
        add.blockhash = get.blockhash;
    }

    fclose(fptr);

    FILE *prv;
    prv = fopen("prev_hash.dat", "w");

    fprintf(prv, "%d", add.blockhash);

    fclose(prv);

    FILE *ptr;
    ptr = fopen("blockhash.dat", "w");

    fprintf(ptr, "%d", add.blockhash + 1);

    fclose(ptr);

    FILE *p;
    p = fopen("blockhash.dat", "r");

    while(fscanf(p, "%d", &get.blockhash) != EOF){
        add.blockhash = get.blockhash;
    }

    fclose(p);

    return add.blockhash;
}

void creating_nodes(){
    system("cls");
    system("color 3");
    
    FILE *ptr;
    ptr = fopen("block.dat", "a+");

    int e;

    printf("\n\n\t\t\tCreating Nodes");

    creating:
        add.nonce = gen_nonce();
        add.blockhash = gen_blockhash();
        add.prev_blockhash = prev_blockhash();

    fprintf(ptr, "%d %d %d\n", add.nonce, add.blockhash, add.prev_blockhash);

    printf("\n\n\n1. Add another node");
    printf("\n\n2. Return to nodes");
    printf("\n3. Return to dashboard");
    printf("\n\n4. Close the program");
    printf("\n\n\n\n\nSelect the desired option: ");
    scanf("%d", &e);

    if(e == 1){
        goto creating;
    }
    else if(e == 3){
        dashboard();
    }
    else if(e == 2){
        nodes();
    }
    else if(e == 4){
        close();
    }
}

void nodes(){
    system("cls");
    system("color 2");

    int c;

    printf("\n\n\t\t\tNodes");
    printf("\n\n\n1. View the blocks");
    printf("\n2. Add a node to the server");
    printf("\n\n3. Return to dashboard");
    printf("\n\n4. Close the program");
    printf("\n\n\n\n\nPress the desire option: ");
    scanf("%d", &c);

    switch(c){
        case 1:
            blocks();
            break;
        case 2:
            creating_nodes();
            break;
        case 3:
            dashboard();
            break;
        case 4:
            close();
            break;
    }
}

int transaction(int d, int b){
    FILE *fptr;
    fptr = fopen("wallet.dat", "r");

    while(fscanf(fptr, "%d %d", &deposit.balance, &deposit.pincode) != EOF){
        if(d == deposit.pincode){
            temp.balance = b + deposit.balance;
            fclose(fptr);
            return temp.balance;
        }
    }
    
}

void update(){
    FILE *old, *new;
    old = fopen("wallet.dat", "r");
    new = fopen("new.dat", "w");

    if(z == 1){
        while(fscanf(old, "%d %d", &last.balance, &last.pincode) != EOF){
            if(q == last.pincode){
                fprintf(new, "%d %d\n", w, last.pincode);
            }
            else{
                fprintf(new, "%d %d\n", last.balance, last.pincode);
            }
        }
    }
    fclose(old);
    fclose(new);
    remove("wallet.dat");
    rename("new.dat", "wallet.dat");
}

void select_wallet(){
    system("cls");
    system("color 3");

    int e, s = 0;

    printf("\n\n\t\t\tLogin to your account!");
    printf("\n\n\nEnter pin code: ");
    scanf("%d", &check.pincode);

    FILE *oldrec, *newrec;
    oldrec = fopen("wallet.dat", "r");
    newrec = fopen("new.dat", "w");

    while(fscanf(oldrec, "%d %d", &get.balance, &get.pincode) != EOF){
        if(check.pincode == get.pincode){
            system("cls");
            s = 1;
            printf("\n\n\t\t\tBalance: %d", get.balance);
            printf("\n\n\n1. Deposit amount");
            printf("\n2. Withdraw amount");
            printf("\n\n3. Return to wallet");
            printf("\n4. Return to dashboard");
            printf("\n\n\n\n\nSelect the desire option: ");
            scanf("%d", &e);

            if(e == 1){
                system("cls");
                printf("\n\n\t\t\tDeposit");
                printf("\n\n\nEnter amount to deposit: ");
                scanf("%d", &add.balance);
                upd.balance = get.balance + add.balance;
                printf("\n\nProcessing");
                for(int i = 0; i < 3; i++){
                    printf(".");
                    delay(999999999);
                }
                printf("\n\nNew balance: %d", upd.balance);
                fprintf(newrec, "%d %d\n", upd.balance, get.pincode);
                printf("\n\nAmount deposit successfully!");
                for(int i = 0; i < 3; i++){
                    delay(1000000000);
                }
            }
            else if(e == 2){
                system("cls");
                printf("\n\n\t\t\tWithdraw");
                printf("\n\n\nEnter the deposit address: ");
                scanf("%d", &temp.temp_pincode);
                q = temp.temp_pincode;
                printf("\nEnter amount to withdraw: ");
                scanf("%d", &temp.temp_balance);
                upd.balance = get.balance - temp.temp_balance;
                w = transaction(temp.temp_pincode, temp.temp_balance);
                delay(1000000000000);
                z = 1;
                fprintf(newrec, "%d %d\n", upd.balance, check.pincode);
            }
            else if(e == 3){
                wallet();
            }
            else if(e == 4){
                dashboard();
            }
        }
        else{
            fprintf(newrec, "%d %d\n", get.balance, get.pincode);
        }
    }
    fclose(oldrec);
    fclose(newrec);
    remove("wallet.dat");
    rename("new.dat", "wallet.dat");

    FILE *t;
    t = fopen("transaction.dat", "a");

    if(e == 1){
        int bank = 0;
        fprintf(t, "%d %d %d\n", bank, check.pincode, add.balance);
    }
    else if(e == 2){
        fprintf(t, "%d %d %d\n", check.pincode, q, temp.temp_balance);
    }

    if(e == 2){
        update();
        printf("\n\nProcessing");
        for (int i = 0; i < 3; i++){
            printf(".");
            delay(999999999);
        }
        printf("\n\nTransfer successfully!");
        for(int i = 0; i < 2; i++){
            delay(1000000000);
        }
        close();
    }

    if((s == 1) || (s == 0)){
        system("cls");
        printf("\n\n\t\t\tMenu");
        printf("\n\n\n1. Return to wallet");
        printf("\n2. Return to dashboard");
        printf("\n\n3. Close the program");
        printf("\n\n\n\n\nSelect the desire option: ");
        scanf("%d", &e);

        if(e == 1){
            wallet();
        }
        else if(e == 2){
            dashboard();
        }
        else if(e == 3){
            close();
        }
    }
}

void add_wallet(){
    system("cls");
    system("color 3");

    FILE *ptr;
    ptr = fopen("wallet.dat", "a+");

    int e;

    creating:
        printf("\t\t\tCreating Wallet");
        printf("\n\n\nSet pin-code: ");
        scanf("%d", &add.pincode);

        fprintf(ptr, "%d %d\n", add.balance, add.pincode);

    printf("\n\n\n1. Create another wallet");
    printf("\n\n2. Return to wallet");
    printf("\n3. Return to dashboard");
    printf("\n\n4. Close the program");
    printf("\n\n\n\n\nSelect the desired option: ");
    scanf("%d", &e);

    if(e == 1){
        goto creating;
    }
    else if(e == 2){
        fclose(ptr);
        wallet();
    }
    else if(e == 3){
        fclose(ptr);
        dashboard();
    }
    else if(e == 4){
        fclose(ptr);
        close();
    }
}

void wallet(){
    int e;

    system("cls");
    system("color 2");

    printf("\n\n\t\t\tWallet");
    printf("\n\n\n1. Login to your wallet");
    printf("\n2. Add a wallet");
    printf("\n\n3. Return to wallet");
    printf("\n4. Return to dashboard");
    printf("\n\n5. Close the program");
    printf("\n\n\n\n\nSelect the desire option: ");
    scanf("%d", &e);

    switch(e){
        case 1:
            select_wallet();
            break;
        case 5:
            close();
            break;
        case 2:
            add_wallet();
            break;
        case 4:
            dashboard();
            break;
        case 3:
            wallet();
    }
}

void dashboard(){
    int c;

    system("cls");
    system("Color 1");

    printf("\n\n\t\t\tDASHBOARD");
    printf("\n\n\n1. Nodes\n2. Wallet\n\n3. Close the program");
    printf("\n\n\n\n\nPress the desire option: ");
    scanf("%d", &c);

    system("cls");

    switch(c){
        case 1:
            nodes();
            break;
        case 2:
            wallet();
            break;
        case 3:
            close();
            break;
    }
}

void close(){
    system("cls");
    system("color 5");
    printf("\n\n\n\t\t\tTHIS PROJECT IS CREATED BY\n\n\t\t\t\tYAR KHAN\n\t\t\t\t  SAAD\n\t\t\t\t USAID\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int main(){
    system("cls");
    system("color 4");
    printf("\nDecentralized Financial System");
    printf("\n\n\n\n\nPlease wait a litlle bit to proceed");
    for (int i = 0; i < 3; i++){
        printf(".");
        delay(999999999);
    }
    dashboard();
}