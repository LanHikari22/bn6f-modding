 if(r0 & 2){
        r7 = chiefStruct->0x3C->0x18; // 0x02001B80->0x18
        r0 = r7->0x20;
        y = pNpc->y; // 0x28
        r0 -= y;
        r1 = r7->0x1C;
        x = pNpc->x; // 0x24
        r1 -= x;
        sub_800117C();
        r0 += 0x20;
        r1 += 0xC0;
        r0 = (r0&r1>>6) << 1 + 1;
        sub_08002DA4();

