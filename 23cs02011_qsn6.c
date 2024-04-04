#include <stdio.h>
#include <string.h>


enum PacketType {
    CONTROL,
    DATA
};


union Packet {
    struct {
        int opcode;
        int status;
    } control;
    char data[100]; // Assuming maximum data payload size of 100 characters
};


struct DataPacket {
    enum PacketType type;
    union Packet content;
};

// Function to assign values to a control packet
void assignControlPacket(struct DataPacket *packet, int opcode, int status) {
    packet->type = CONTROL;
    packet->content.control.opcode = opcode;
    packet->content.control.status = status;
}

// Function to assign values to a data packet
void assignDataPacket(struct DataPacket *packet, const char *data) {
    packet->type = DATA;
    strncpy(packet->content.data, data, sizeof(packet->content.data));
}

// Function to print the packet contents
void printPacket(const struct DataPacket *packet){
    if (packet->type == CONTROL) {
        printf("Control Packet: Opcode=%d, Status=%d\n", packet->content.control.opcode, packet->content.control.status);
    } else if (packet->type == DATA) {
        printf("Data Packet: Data=%s\n", packet->content.data);
    }
}

int main() {
    
    struct DataPacket packets[3];

    
    assignControlPacket(&packets[0], 1, 200);
    assignDataPacket(&packets[1], "This is a data packet.");
    assignControlPacket(&packets[2], 2, 404);

    // Print the packet contents
    for (int i = 0; i < 3; i++) {
        printPacket(&packets[i]);
    }

    return 0;
}
