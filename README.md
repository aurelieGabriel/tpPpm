[![Build Status](https://travis-ci.org/gatoravi/mpileup2readcounts.svg?branch=master)](https://travis-ci.org/gatoravi/mpileup2readcounts)
##Synopsis
Get the readcounts at a locus by piping samtools mpileup output. The mpileup can contain one or several samples.
This program has been tested on samtools v1.3.1

##Install samtools 

##Compile mpileup2readcounts : 
```
g++ -std=c++11 -O3 mpileup2readcounts.cc -o mpileup2readcounts
```

##Usage

```
samtools mpileup -f ref.fa -l regions.bed BAM/*.bam | sed 's/		/	* 	*/g' | mpileup2readcounts 0 -5 false
```
Samtools arguments :
- FASTA file
- bed file
- BAM files : several samples can be parsed

Three options for mpileup2readcounts :
- 0 to parse all sample otherwise specify the number of the sample (for example 1 for the first sample)
- BQcut : base quality score cutoff for each mapped/unmapped base, only those larger than cutoff will be output in the result, to use no filter set BQcut to -5
- true to ignore indels 

##Example output

| Parameter | Default value | Description |
|-----------|--------------:|-------------| 
| min_dp    |            30 | Minimum median coverage to consider a site. In addition, at least 10 samples have to be covered by min_dp. |
| min_ao | 3 | Minimum number of non-ref reads in at least one sample to consider a site |
| nsplit | 1 | Split the bed file in nsplit pieces and run in parallel |
| min_qval | 50 | qvalue threshold in [Phred scale](https://en.wikipedia.org/wiki/Phred_quality_score) to consider a variant |
| sb_type | SOR | Strand bias measure, either SOR, RVSB or FS |
| sb_snv | 100 or 1000 | Strand bias threshold for SNVs (100 (1000 if FS) = no filter) |
| sb_indel | 100 or 1000 | Strand bias threshold for indels (100 (1000 if FS) = no filter)|
| map_qual | 20 | Min mapping quality (passed to samtools) |
| base_qual | 20 | Min base quality (passed to samtools) |
| max_DP | 30000 | Downsample coverage per sample (passed to samtools) |
| use_file_name |   | Put this argument to use the bam file names as sample names. By default the sample name is extracted from the bam file SM tag. |
| all_SNVs |   | Put this argument to output all SNVs, even when no variant is detected. Note that positions with zero coverage for all samples might still be missing depending on how the region split is performed |
| no_plots |   | Put this argument to remove pdf plots of regressions from the output |
| no_labels |   | Put this argument for not labeling the outliers on regression plots |
| no_indels |   | Put this argument to do not perform the variant calling on insertions and deletions |
| no_contours |   | Put this argument to do not plot qvalues contours (for qvalue threshold={10,30,50,70,100} by default) and do not plot minimum detectable allelic fraction in function of coverage |
| out_folder | --bam_folder | Output folder, by default equals to the input bam folder |
| out_vcf | all_variants.vcf | File name of final VCF |
| bed |   | BED file containing a list of regions (or positions) where needlestack should be run |
| region |   | A region in format CHR:START-END where calling should be done |
| pairs_file | | A tab-delimited file containing two columns (normal and tumor sample names) for each sample in line. This enables matched tumor/normal pair calling features (see below) |
| power_min_af |  | Allelic fraction used to classify genotypes to 0/0 or ./. depending of the power to detect a variant at this fraction (see below) |
| extra_robust_gl | | Add this argument to perform extra-robust regression (useful for common germline SNPs, see below) |
| sigma_normal | 0.1 | Sigma parameter for negative binomial modeling of expected germline allelic fraction. We strongly recommend not to change this parameter unless you really know what it means |
| input_vcf |   | A VCF file (from GATK) where calling should be done. Needlestack will extract DP and AO from this VCF (DP and AD fields) and annotate it with phred q-value score (`FORMAT/QVAL` field), error rate (`INFO/ERR`) and over-dispersion sigma parameter (`INFO/SIG`). WARNING: by default, only work with split (coreutils) version > 8.13 |

| chr |	loc	| ref	| depth	| A	| T	| C	| G	| a	| t	| c	| g	| Insertion	| Deletion	| depth	| A	| T	| C	| G	| a	| t	| c	| g	| Insertion	| Deletion	|
| 17 | 7572814	| C	| 25	| 0	| 0	| 23	| 0	| 0	| 0	| 2	| 0	| NA	| NA	| 8	| 0	| 0	| 8	| 0	| 0	| 0	| 0	| 0	| NA |	NA |
| 17	| 7572817	| C	| 28	| 0	| 0	| 26	| 0	| 0	| 0	| 2	| 0	| NA	| NA	| 8	| 0	| 0	| 8	| 0	| 0	| 0	| 0	| 0	| NA	| NA|
| 17	| 7579643	| C	| 48	| 0	| 0	| 9	| 0	| 0	| 0	| 39	| 0	| NA	| 4:ccccagccctccaggt|2:CCCCAGCCCTCCAGGT	| 9	| 0	| 0	| 6	| 0	| 0	| 0	| 3	| 0	| NA	| NA|


### Line content
Common informations for all samples: 
- chromosome
- position on the chromosome
- reference base

For each sample :
- depth
- ATCG/atcg count
- insertions 
- deletions : in the example, there are 6 deletions found at position 7579643 for the first sample, 2 on the forward strand and 4 on the reverse strand

