#include <stdio.h>
#include <stdint.h>

// Modul Harga Objek Rumah
unsigned long hitung_harga_objek_rumah()
{
    return 1500000000; // Harga objek rumah
}

// Modul Nilai Sosiologis
double hitung_nilai_sosiologis()
{
    return 5000000.0; // Nilai Sosiologis
}

// Modul Pengolahan Biaya Honorarium
double hitung_biaya_honorarium(unsigned long hargaObjekRumah, double nilaiSosiologis, float *persentaseHonor)
{
    if (hargaObjekRumah <= 100000000)
    {
        *persentaseHonor = 0.025f;
    }
    else if (hargaObjekRumah <= 1000000000)
    {
        *persentaseHonor = 0.015f;
    }
    else
    {
        *persentaseHonor = 0.010f;
    }

    // Menghitung total honor setelah mengonversi persentase ke nilai nominal
    return hargaObjekRumah * (*persentaseHonor) + nilaiSosiologis;
}

// Modul Output
void tampilkan_output(unsigned long hargaObjekRumah, double nilaiSosiologis, float persentaseHonor, double totalHonor)
{
    printf("================================\n");
    printf("PROGRAM PENGHITUNG CREDIT RUMAH\n");
    printf("================================\n\n");

    printf("Harga Objek Rumah: Rp.%lu\n", hargaObjekRumah);
    printf("Nilai sosiologis: Rp.%.lf\n", nilaiSosiologis);
    printf("Persentase honor: %.2f%%\n", persentaseHonor * 100); // Menampilkan persentase dengan 2 desimal
    printf("Total Honor: Rp.%.lf\n", totalHonor);
}

int main()
{
    // Memanggil modul Harga Objek Rumah
    unsigned long hargaObjekRumah = hitung_harga_objek_rumah();

    // Memanggil modul Nilai Sosiologis
    double nilaiSosiologis = hitung_nilai_sosiologis();

    // Memanggil modul Pengolahan Biaya Honorarium
    float persentaseHonor;
    double totalHonor = hitung_biaya_honorarium(hargaObjekRumah, nilaiSosiologis, &persentaseHonor);

    // Memanggil modul Output
    tampilkan_output(hargaObjekRumah, nilaiSosiologis, persentaseHonor, totalHonor);

    return 0;
}
